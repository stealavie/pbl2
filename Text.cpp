#include "Text.h"

Text::Text(SDL_Renderer* renderer, TTF_Font* font, const std::string& text,
			int x,int y,int w,int h,int Text_area_w, int Text_area_h, int Scroll_width)
	:renderer(renderer),font(font),text(text),x(x),y(y),w(w),h(h),Text_area_w(Text_area_w),Text_area_h(Text_area_h),Scroll_width(Scroll_width)
{}

Text::~Text()
{
	renderer = NULL;
	font = NULL;
	TTF_Quit();
	SDL_Quit();
}

void Text::RenderTextWithScrolling(const std::string& text, int maxWidth, int maxHeight, int yoff)
{
	SDL_Color color = { 255,255,255 };
	SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped(font, text.c_str(), color, maxWidth);
	SDL_Texture* textTex = SDL_CreateTextureFromSurface(renderer, textSurface);

	int textWidth = textSurface->w;
	int textHeight = textSurface->h;
	SDL_QueryTexture(textTex, NULL,NULL, &textWidth, &textHeight);

	int renderHeight = (textHeight > maxHeight) ? maxHeight : textHeight;

	SDL_Rect renderRect = { x,y + yoff,textWidth,renderHeight };
	SDL_RenderCopy(renderer, textTex, NULL, &renderRect);

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTex);
}

void Text::RenderScrollBar(int totalHeight)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	float scrollBar_h = static_cast<float>(Text_area_h) / static_cast<float>(totalHeight) * Text_area_h;
	float scrollBar_position = static_cast<float>(this->scrollPosition) / static_cast<float>(totalHeight) * Text_area_h;

	SDL_Rect scrollBarRect = { x+w-Scroll_width,y + static_cast<int>(scrollBar_position),this->Scroll_width,static_cast<int>(scrollBar_h) };
	SDL_RenderFillRect(renderer, &scrollBarRect);
}


void Text::HandleEvent(SDL_Event* e)
{
	switch (e->type)
	{
	case SDL_MOUSEBUTTONDOWN:
	{
		if (e->button.button == SDL_BUTTON_LEFT)
		{
			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);

			int scrollBarX = this->w + this->x - this->Scroll_width;
			int scrollBarY = y + static_cast<int>((static_cast<float>(this->scrollPosition) / static_cast<float>(this->text.length())) * Text_area_h);
			int scrollBarHeight = static_cast<int>((static_cast<float>(this->Text_area_h) / static_cast<float>(this->text.length())) * Text_area_h);

			if (mouseX >= scrollBarX && mouseX <= scrollBarX + this->Scroll_width &&
				mouseY >= scrollBarY && mouseY <= scrollBarY + scrollBarHeight)
			{
				this->isClickScrollBar = true;
			}
		}
		break;
	}
	case SDL_MOUSEBUTTONUP:
	{
		if (e->button.button == SDL_BUTTON_LEFT)
		{
			this->isClickScrollBar = false;
		}
		break;
	}
	case SDL_MOUSEMOTION:
	{
		if (this->isClickScrollBar)
		{
			int mouseY;
			SDL_GetMouseState(nullptr, &mouseY);

			int newScrollPosition = static_cast<int>((static_cast<float>(mouseY - y) / static_cast<float>(this->Text_area_h)) * text.length());

			if (newScrollPosition >= 0 && newScrollPosition <= (text.length() - Text_area_h))
			{
				scrollPosition = newScrollPosition;
			}
		}
		break;
	}
	case SDL_MOUSEWHEEL:
	{
		if (e->wheel.y > 0)
		{
			// Scroll up
			scrollPosition = (scrollPosition - this->Scroll_speed > 0) ? (scrollPosition - this->Scroll_speed) : 0;
		}
		else if (e->wheel.y < 0)
		{
			// Scroll down
			scrollPosition = (static_cast<int>(text.length()) - Text_area_h < scrollPosition + Scroll_speed) ? (static_cast<int>(text.length()) - Text_area_h) : scrollPosition + Scroll_speed;
		}
		break;
	}
	}
}


void Text::draw()
{
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set background color to black
	//SDL_RenderClear(renderer);

	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set border color to white
	SDL_Rect borderRect = { x, y, Text_area_w, Text_area_h };
	SDL_RenderDrawRect(renderer, &borderRect);

	int visibleTextHeight = Text_area_h;

	std::string visibleText = text.substr(scrollPosition, visibleTextHeight);

	RenderTextWithScrolling(visibleText, Text_area_w, visibleTextHeight, 0);
	RenderScrollBar(static_cast<int>(text.length()));

}


