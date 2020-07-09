#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

const int pixPerChar = 6; // length of each charicter in pixels
const int pixPerSpace = 1; // each space inbetween charicters is 1 pixel
int currentMenu = 0;

// TODO: Pull out all scenes into their own separate classes
// TODO: Start creating the object testing arena

class MainMenu : public olc::PixelGameEngine
{
public:
	// User Information
	int currentMenuSelection = 1;
	// Main Menu Title
	const std::string mainMenuTitleText = "Elf Fortress";
	int mainMenuTitlePosX;
	int mainMenuTitlePosY;

	// Subtitle
	std::string subtitleText;
	int subtitlePosX;
	int subtitlePosY;

	// Menu item 1, "Create New World"
	const int menu1ID = 1;
	const std::string menu1Text = "Create New World";
	olc::Pixel menu1Color = olc::WHITE;
	int menu1PosX;
	int menu1PosY;

	// Menu item 2, "Load Game"
	const int menu2ID = 2;
	const std::string menu2Text = "Load Game";
	olc::Pixel menu2Color = olc::DARK_GREY;
	int menu2PosX;
	int menu2PosY;

	// Menu item3, "Object Testing Arena"
	const int menu3ID = 3;
	const std::string menu3Text = "Object Testing Arena";
	olc::Pixel menu3Color = olc::DARK_GREY;
	int menu3PosX;
	int menu3PosY;

	// Menu item 4, "About EF"
	const int menu4ID = 4;
	const std::string menu4Text = "About EF";
	olc::Pixel menu4Color = olc::DARK_GREY;
	int menu4PosX;
	int menu4PosY;

	// Menu item 5, "Quit"
	const int menu5ID = 5;
	const std::string menu5Text = "Quit";
	olc::Pixel menu5Color = olc::DARK_GREY;
	int menu5PosX;
	int menu5PosY;

	int StringLengthPix(const std::string str, int uiScale)
	{
		int sum = 0;
		for (int i = 0; i < str.length(); i++)
		{
			sum += pixPerChar * uiScale + 1; // char
			if (i < str.length() - 1) // no space at the end
				sum += pixPerSpace * uiScale; // add space inbetween chars
		}

		return sum; // This may not be a precise measurement, but it's close enough for now
	}

	std::string CreateSubtitle()
	{
		const std::string subtitleTraits[9] = { "Nature", "Trees", "Pointy Ears", "Wisdom", "Divinity", "Androgyny", "Immortality", "Magic", "Vanity" };
		int n1 = rand() % 9; // TODO: this might not be working. Appears to be picking the same numbers every time.
		int n2 = rand() % 9;
		std::string s1 = subtitleTraits[n1];
		std::string s2 = subtitleTraits[n2];
		std::string fullstring = "Histories of " + s1 + " and " + s2;

		return fullstring;
	}

	void Load()
	{
		mainMenuTitlePosX = ScreenWidth() / 2 - StringLengthPix(mainMenuTitleText, 2) / 2;
		mainMenuTitlePosY = 10;

		subtitleText = CreateSubtitle();
		subtitlePosX = ScreenWidth() / 2 - StringLengthPix(subtitleText, 1) / 2;
		subtitlePosY = mainMenuTitlePosY + 20;

		menu1PosX = ScreenWidth() / 2 - StringLengthPix(menu1Text, 1) / 2;
		menu1PosY = subtitlePosY + 30;

		menu2PosX = ScreenWidth() / 2 - StringLengthPix(menu2Text, 1) / 2;
		menu2PosY = menu1PosY + 15;

		menu3PosX = ScreenWidth() / 2 - StringLengthPix(menu3Text, 1) / 2;
		menu3PosY = menu2PosY + 15;

		menu4PosX = ScreenWidth() / 2 - StringLengthPix(menu4Text, 1) / 2;
		menu4PosY = menu3PosY + 15;

		menu5PosX = ScreenWidth() / 2 - StringLengthPix(menu5Text, 1) / 2;
		menu5PosY = menu4PosY + 15;
	}

	void Run()
	{
		// Main Menu Navigation
		if (GetKey(olc::DOWN).bPressed)
		{
			currentMenuSelection += 1;
		}
		if (GetKey(olc::UP).bPressed)
		{
			currentMenuSelection -= 1;
		}
		if (currentMenuSelection > 5) currentMenuSelection = 1;
		if (currentMenuSelection < 1) currentMenuSelection = 5;

		// If the user hits ENTER on a menu, load that menu
		if (GetKey(olc::ENTER).bPressed)
		{
			currentMenu = currentMenuSelection;
		}

		// Update the menu color based on the current menu selection
		menu1Color = olc::DARK_GREY;
		menu2Color = olc::DARK_GREY;
		menu3Color = olc::DARK_GREY;
		menu4Color = olc::DARK_GREY;
		menu5Color = olc::DARK_GREY;
		switch (currentMenuSelection)
		{
		case 1:
			menu1Color = olc::WHITE;
			break;
		case 2:
			menu2Color = olc::WHITE;
			break;
		case 3:
			menu3Color = olc::WHITE;
			break;
		case 4:
			menu4Color = olc::WHITE;
			break;
		case 5:
			menu5Color = olc::WHITE;
			break;
		}

		// Draw title
		DrawString({ mainMenuTitlePosX, mainMenuTitlePosY }, mainMenuTitleText, olc::WHITE, 2);
		// Draw Subtitle
		DrawString({ subtitlePosX, subtitlePosY }, subtitleText, olc::RED);
		// Draw menu item 1, "Create New World"
		DrawString({ menu1PosX, menu1PosY }, menu1Text, menu1Color);
		// Draw menu item 2, "Load Game"
		DrawString({ menu2PosX, menu2PosY }, menu2Text, menu2Color);
		// Draw menu item 3, "Object Testing Arena"
		DrawString({ menu3PosX, menu3PosY }, menu3Text, menu3Color);
		// Draw menu, "About EF"
		DrawString({ menu4PosX, menu4PosY }, menu4Text, menu4Color);
		// Draw menu, Quit
		DrawString({ menu5PosX, menu5PosY }, menu5Text, menu5Color);
	}
};

class ObjectTestingArena : public olc::PixelGameEngine
{
public:
	void Load()
	{
	}

	void Run()
	{
		// Draw black background
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(olc::BLACK));
	}
};

class Game : public olc::PixelGameEngine
{
public:
	Game()
	{
		sAppName = "Elf Fortress";
	}

public:

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here

		

		// Debug output
		std::cout << "Menu Title Pixel Width: " << StringLengthPix(mainMenuTitleText, 2) << std::endl;
		std::cout << "Menu Title PosX: " << mainMenuTitlePosX << std::endl;
		std::cout << "Menu Title PosY: " << mainMenuTitlePosY << std::endl;
		std::cout << " " << std::endl; 
		std::cout << "Subtitle Pixel Width: " << StringLengthPix(subtitleText, 1) << std::endl;
		std::cout << "Subtitle PosX: " << subtitlePosX << std::endl;
		std::cout << "Subtitle PosY: " << subtitlePosY << std::endl;
		std::cout << " " << std::endl;
		// End Debug output

		// Draw black background
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(olc::BLACK));

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		
		if (currentMenu == 0) RunMainMenu();
		if (currentMenu == 3) RunObjectTestingArena();

		return true;
	}
};


int main()
{
	Game game;
	if (game.Construct(500, 300, 2, 2))
		game.Start();

	return 0;
}