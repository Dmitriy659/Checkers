#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace sf;
using namespace std;

bool check_move(vector <vector<int>>& board, bool mov, int last_x, int last_y, int mouse_x, int mouse_y)
{
	if (mov)
	{
		if (board[last_y][last_x] == 1)
		{
			if (abs(mouse_x - last_x) == 1 && abs(mouse_y - last_y) == 1 && board[mouse_y][mouse_x] == 0 && mouse_y - last_y == -1)
				return 1;
			else
				return 0;
		}
		else if (board[last_y][last_x] == 3)
		{
			if ((abs(mouse_x - last_x) == abs(mouse_y - last_y)) && board[mouse_y][mouse_x] == 0)
			{
				int x, y;
				x = last_x;
				y = last_y;
				if (mouse_x < last_x && mouse_y > last_y) //вниз влево
				{
					x--;
					y++;
					while (x != mouse_x && y != mouse_y)
					{
						if (board[y][x] == 1 || board[y][x] == 3)
							return 0;
						if ((board[y][x] == 2 || board[y][x] == 4) && (board[y + 1][x - 1] == 2 || board[y + 1][x - 1] == 4))
							return 0;
						x--;
						y++;
					}
				}
				else if (mouse_x > last_x && mouse_y > last_y) //вниз вправво
				{
					x++;
					y++;
					while (x != mouse_x && y != mouse_y)
					{
						if (board[y][x] == 1 || board[y][x] == 3)
							return 0;
						if ((board[y][x] == 2 || board[y][x] == 4) && (board[y + 1][x + 1] == 2 || board[y + 1][x + 1] == 4))
							return 0;
						x++;
						y++;
					}
				}
				else if (mouse_x < last_x && mouse_y < last_y) //вверх влево
				{
					x--;
					y--;
					while (x != mouse_x && y != mouse_y)
					{
						if (board[y][x] == 1 || board[y][x] == 3)
							return 0;
						if ((board[y][x] == 2 || board[y][x] == 4) && (board[y - 1][x - 1] == 2 || board[y - 1][x - 1] == 4))
							return 0;
						x--;
						y--;
					}
				}
				else if (mouse_x > last_x && mouse_y < last_y) //вверх вправво
				{
					x++;
					y--;
					while (x != mouse_x && y != mouse_y)
					{
						if (board[y][x] == 1 || board[y][x] == 3)
							return 0;
						if ((board[y][x] == 2 || board[y][x] == 4) && (board[y - 1][x + 1] == 2 || board[y - 1][x + 1] == 4))
							return 0;
						x++;
						y--;
					}
				}
				return 1;
			}
			else
				return 0;
		}
	}
	if (!mov)
	{
		if (board[last_y][last_x] == 2)
		{
			if (abs(mouse_x - last_x) == 1 && abs(mouse_y - last_y) == 1 && board[mouse_y][mouse_x] == 0 && mouse_y - last_y == 1)
				return 1;
			else
				return 0;
		}
		else if (board[last_y][last_x] == 4)
		{
			if (abs(mouse_x - last_x) == abs(mouse_y - last_y) && board[mouse_y][mouse_x] == 0)
			{
				int x, y;
				x = last_x;
				y = last_y;
				if (mouse_x < last_x && mouse_y > last_y) //вниз влево
				{
					x--;
					y++;
					while (x != mouse_x && y != mouse_y)
					{
						if (board[y][x] == 2 || board[y][x] == 4)
							return 0;
						if ((board[y][x] == 1 || board[y][x] == 3) && (board[y + 1][x - 1] == 1 || board[y + 1][x - 1] == 3))
							return 0;
						x--;
						y++;
					}
				}
				else if (mouse_x > last_x && mouse_y > last_y) //вниз вправво
				{
					x++;
					y++;
					while (x != mouse_x && y != mouse_y)
					{
						if (board[y][x] == 2 || board[y][x] == 4)
							return 0;
						if ((board[y][x] == 1 || board[y][x] == 3) && (board[y + 1][x + 1] == 1 || board[y + 1][x + 1] == 3))
							return 0;
						x++;
						y++;
					}
				}
				else if (mouse_x < last_x && mouse_y < last_y) //вверх влево
				{
					x--;
					y--;
					while (x != mouse_x && y != mouse_y)
					{
						if (board[y][x] == 2 || board[y][x] == 4)
							return 0;
						if ((board[y][x] == 1 || board[y][x] == 3) && (board[y - 1][x - 1] == 1 || board[y - 1][x - 1] == 3))
							return 0;
						x--;
						y--;
					}
				}
				else if (mouse_x > last_x && mouse_y < last_y) //вверх вправво
				{
					x++;
					y--;
					while (x != mouse_x && y != mouse_y)
					{
						if (board[y][x] == 2 || board[y][x] == 4)
							return 0;
						if ((board[y][x] == 1 || board[y][x] == 3) && (board[y - 1][x + 1] == 1 || board[y - 1][x + 1] == 3))
							return 0;
						x++;
						y--;
					}
				}
				return 1;
			}
			else
				return 0;
		}
	}
}

bool check_possibility_eat(vector <vector<int>>& board, bool mov, int last_x, int last_y, int mouse_x, int mouse_y)
{
	if (mov)
	{
		if (board[last_y][last_x] == 1)
		{
			if (abs(mouse_x - last_x) == 2 && abs(mouse_y - last_y) == 2 && board[mouse_y][mouse_x] == 0)
			{
				if (mouse_y > last_y && mouse_x < last_x) //вниз влево
					if (board[mouse_y - 1][mouse_x + 1] == 2 || board[mouse_y - 1][mouse_x + 1] == 4)
					{
						board[mouse_y - 1][mouse_x + 1] = 0;
						return 1;
					}
				if (mouse_y > last_y && mouse_x > last_x) //вниз вправо
					if (board[mouse_y - 1][mouse_x - 1] == 2 || board[mouse_y - 1][mouse_x - 1] == 4)
					{
						board[mouse_y - 1][mouse_x - 1] = 0;
						return 1;
					}
				if (mouse_y < last_y && mouse_x < last_x) //вверх влево
					if (board[mouse_y + 1][mouse_x + 1] == 2 || board[mouse_y + 1][mouse_x + 1] == 4)
					{
						board[mouse_y + 1][mouse_x + 1] = 0;
						return 1;
					}
				if (mouse_y < last_y && mouse_x > last_x) //вверх вправо
					if (board[mouse_y + 1][mouse_x - 1] == 2 || board[mouse_y + 1][mouse_x - 1] == 4)
					{
						board[mouse_y + 1][mouse_x - 1] = 0;
						return 1;
					}
			}
		}
		else if (board[last_y][last_x] == 3 && check_move(board, mov, last_x, last_y, mouse_x, mouse_y))
		{
			if (abs(mouse_x - last_x) == abs(mouse_y - last_y) && board[mouse_y][mouse_x] == 0)
			{
				if (mouse_y > last_y && mouse_x < last_x) //вниз влево
					if (board[mouse_y - 1][mouse_x + 1] == 2 || board[mouse_y - 1][mouse_x + 1] == 4)
					{
						board[mouse_y - 1][mouse_x + 1] = 0;
						return 1;
					}
				if (mouse_y > last_y && mouse_x > last_x) //вниз вправо
					if (board[mouse_y - 1][mouse_x - 1] == 2 || board[mouse_y - 1][mouse_x - 1] == 4)
					{
						board[mouse_y - 1][mouse_x - 1] = 0;
						return 1;
					}
				if (mouse_y < last_y && mouse_x < last_x) //вверх влево
					if (board[mouse_y + 1][mouse_x + 1] == 2 || board[mouse_y + 1][mouse_x + 1] == 4)
					{
						board[mouse_y + 1][mouse_x + 1] = 0;
						return 1;
					}
				if (mouse_y < last_y && mouse_x > last_x) //вверх вправо
					if (board[mouse_y + 1][mouse_x - 1] == 2 || board[mouse_y + 1][mouse_x - 1] == 4)
					{
						board[mouse_y + 1][mouse_x - 1] = 0;
						return 1;
					}
			}
		}
	}
	else if (!mov)
	{
		if (board[last_y][last_x] == 2)
		{
			if (abs(mouse_x - last_x) == 2 && abs(mouse_y - last_y) == 2 && board[mouse_y][mouse_x] == 0)
			{
				if (mouse_y > last_y && mouse_x < last_x) //вниз влево
					if (board[mouse_y - 1][mouse_x + 1] == 1 || board[mouse_y - 1][mouse_x + 1] == 3)
					{
						board[mouse_y - 1][mouse_x + 1] = 0;
						return 1;
					}
				if (mouse_y > last_y && mouse_x > last_x) //вниз вправо
					if (board[mouse_y - 1][mouse_x - 1] == 1 || board[mouse_y - 1][mouse_x - 1] == 3)
					{
						board[mouse_y - 1][mouse_x - 1] = 0;
						return 1;
					}
				if (mouse_y < last_y && mouse_x < last_x) //вверх влево
					if (board[mouse_y + 1][mouse_x + 1] == 1 || board[mouse_y + 1][mouse_x + 1] == 3)
					{
						board[mouse_y + 1][mouse_x + 1] = 0;
						return 1;
					}
				if (mouse_y < last_y && mouse_x > last_x) //вверх вправо
					if (board[mouse_y + 1][mouse_x - 1] == 1 || board[mouse_y + 1][mouse_x - 1] == 3)
					{
						board[mouse_y + 1][mouse_x - 1] = 0;
						return 1;
					}
			}
		}
		else if (board[last_y][last_x] == 4)
		{
			if (abs(mouse_x - last_x) == abs(mouse_y - last_y) && board[mouse_y][mouse_x] == 0 && check_move(board, mov, last_x, last_y, mouse_x, mouse_y))
			{
				if (mouse_y > last_y && mouse_x < last_x) //вниз влево
					if (board[mouse_y - 1][mouse_x + 1] == 1 || board[mouse_y - 1][mouse_x + 1] == 3)
					{
						board[mouse_y - 1][mouse_x + 1] = 0;
						return 1;
					}
				if (mouse_y > last_y && mouse_x > last_x) //вниз вправо
					if (board[mouse_y - 1][mouse_x - 1] == 1 || board[mouse_y - 1][mouse_x - 1] == 3)
					{
						board[mouse_y - 1][mouse_x - 1] = 0;
						return 1;
					}
				if (mouse_y < last_y && mouse_x < last_x) //вверх влево
					if (board[mouse_y + 1][mouse_x + 1] == 1 || board[mouse_y + 1][mouse_x + 1] == 3)
					{
						board[mouse_y + 1][mouse_x + 1] = 0;
						return 1;
					}
				if (mouse_y < last_y && mouse_x > last_x) //вверх вправо
					if (board[mouse_y + 1][mouse_x - 1] == 1 || board[mouse_y + 1][mouse_x - 1] == 3)
					{
						board[mouse_y + 1][mouse_x - 1] = 0;
						return 1;
					}
			}
		}
	}
	return 0;
}

bool check_fight(vector <vector<int>>& board, bool move)
{
	int x, y;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (board[j][i] == 2 && !move)
			{
				if (j - 2 >= 0 && i + 2 < 8) //вниз влево
					if ((board[j - 1][i + 1] == 1 || board[j - 1][i + 1] == 3) && board[j - 2][i + 2] == 0)
						return 1;
				if (j + 2 < 8 && i + 2 < 8) //вниз вправо
					if ((board[j + 1][i + 1] == 1 || board[j + 1][i + 1] == 3) && board[j + 2][i + 2] == 0)
						return 1;
				if (j - 2 >= 0 && i - 2 >= 0) //вверх влево
					if ((board[j - 1][i - 1] == 1 || board[j - 1][i - 1] == 3) && board[j - 2][i - 2] == 0)
						return 1;
				if (j + 2 < 8 && i - 2 >= 0) //вверх вправо
					if ((board[j + 1][i - 1] == 1 || board[j + 1][i - 1] == 3) && board[j + 2][i - 2] == 0)
						return 1;
			}
			else if (board[j][i] == 4 && !move)
			{
				if (j - 1 >= 0 && i + 1 < 8) //вниз влево
				{
					x = j - 1;
					y = i + 1;
					bool m = 0;
					while (x >= 0 && y < 8)
					{
						if (x - 1 >= 0 && y + 1 < 8)
						{ 
							if (board[x][y] == 2 || board[x][y] == 4)
								m = 1;
							if ((board[x][y] == 1 || board[x][y] == 3) && (board[x - 1][y + 1] == 1 || board[x - 1][y + 1] == 3))
								m = 1;
							if ((board[x][y] == 1 || board[x][y] == 3) && board[x - 1][y + 1] == 0 && !m)
								return 1;
						}
						x--;
						y++;
					}
				}
				if (j + 1 < 8 && i + 1 < 8) //вниз вправо
				{
					x = j + 1;
					y = i + 1;
					bool m = 0;
					while (x < 8 && y < 8)
					{
						if (x + 1 < 8 && y + 1 < 8)
						{
							if (board[x][y] == 2 || board[x][y] == 4)
								m = 1;
							if ((board[x][y] == 1 || board[x][y] == 3) && (board[x + 1][y + 1] == 1 || board[x + 1][y + 1] == 3))
								m = 1;
							if ((board[x][y] == 1 || board[x][y] == 3) && board[x + 1][y + 1] == 0 && !m)
								return 1;
						}
						x++;
						y++;
					}
				}
				if (j - 1 >= 0 && i - 1 >= 0) //вверх влево
				{
					x = j - 1;
					y = i - 1;
					bool m = 0;
					while (x >= 0 && y >= 0)
					{
						if (x - 1 >= 0 && y - 1 >= 0)
						{
							if (board[x][y] == 2 || board[x][y] == 4)
								m = 1;
							if ((board[x][y] == 1 || board[x][y] == 3) && (board[x - 1][y - 1] == 1 || board[x - 1][y - 1] == 3))
								m = 1;
							if ((board[x][y] == 1 || board[x][y] == 3) && board[x - 1][y - 1] == 0 && !m)
								return 1;
						}
						x--;
						y--;
					}
				}
				if (j + 1 < 8 && i - 1 >= 0) //вверх вправо
				{
					x = j + 1;
					y = i - 1;
					bool m = 0;
					while (x < 8 && y >= 0)
					{
						if (x + 1 < 8 && y - 1 >= 0)
						{
							if (board[x][y] == 2 || board[x][y] == 4)
								m = 1;
							if ((board[x][y] == 1 || board[x][y] == 3) && (board[x + 1][y - 1] == 1 || board[x + 1][y - 1] == 3))
								m = 1;
							if ((board[x][y] == 1 || board[x][y] == 3) && board[x + 1][y - 1] == 0 && !m)
								return 1;
						}
						x++;
						y--;
					}
				}
			}
			 else if (board[j][i] == 1 && move)
			{
				if (j - 2 >= 0 && i + 2 < 8) //вниз влево
					if ((board[j - 1][i + 1] == 2 || board[j - 1][i + 1] == 4) && board[j - 2][i + 2] == 0)
						return 1;
				if (j + 2 < 8 && i + 2 < 8) //вниз вправо
					if ((board[j + 1][i + 1] == 2 || board[j + 1][i + 1] == 4) && board[j + 2][i + 2] == 0)
						return 1;
				if (j - 2 >= 0 && i - 2 >= 0) //вверх влево
					if ((board[j - 1][i - 1] == 2 || board[j - 1][i - 1] == 4) && board[j - 2][i - 2] == 0)
						return 1;
				if (j + 2 < 8 && i - 2 >= 0) //вверх вправо
					if ((board[j + 1][i - 1] == 2 || board[j + 1][i - 1] == 4) && board[j + 2][i - 2] == 0)
						return 1;
			}
			 else if (board[j][i] == 3 && move)
			{
				if (j - 1 >= 0 && i + 1 < 8) //вниз влево
				{
					x = j - 1;
					y = i + 1;
					bool m = 0;
					while (x >= 0 && y < 8)
					{
						if (x - 1 >= 0 && y + 1 < 8)
						{
							if (board[x][y] == 1 || board[x][y] == 3)
								m = 1;
							if ((board[x][y] == 2 || board[x][y] == 4) && (board[x - 1][y + 1] == 2 || board[x - 1][y + 1] == 4))
								m = 1;
							if ((board[x][y] == 2 || board[x][y] == 4) && board[x - 1][y + 1] == 0 && !m)
								return 1;
						}
						x--;
						y++;
					}
				}
				if (j + 1 < 8 && i + 1 < 8) //вниз вправо
				{
					x = j + 1;
					y = i + 1;
					bool m = 0;
					while (x < 8 && y < 8)
					{
						if (x + 1 < 8 && y + 1 < 8)
						{
							if (board[x][y] == 1 || board[x][y] == 3)
								m = 1;
							if ((board[x][y] == 2 || board[x][y] == 4) && (board[x + 1][y + 1] == 2 || board[x + 1][y + 1] == 4))
								m = 1;
							if ((board[x][y] == 2 || board[x][y] == 4) && board[x + 1][y + 1] == 0 && !m)
								return 1;
						}
						x++;
						y++;
					}
				}
				if (j - 1 >= 0 && i - 1 >= 0) //вверх влево
				{
					x = j - 1;
					y = i - 1;
					bool m = 0;
					while (x >= 0 && y >= 0)
					{
						if (x - 1 >= 0 && y - 1 >= 0)
						{
							if (board[x][y] == 1 || board[x][y] == 3)
								m = 1;
							if ((board[x][y] == 2 || board[x][y] == 4) && (board[x - 1][y - 1] == 2 || board[x - 1][y - 1] == 4))
								m = 1;
							if ((board[x][y] == 2 || board[x][y] == 4) && board[x - 1][y - 1] == 0 && !m)
								return 1;
						}
						x--;
						y--;
					}
				}
				if (j + 1 < 8 && i - 1 >= 0) //вверх вправо
				{
					x = j + 1;
					y = i - 1;
					bool m = 0;
					while (x < 8 && y >= 0)
					{
						if (x + 1 < 8 && y - 1 >= 0)
						{
							if (board[x][y] == 1 || board[x][y] == 3)
								m = 1;
							if ((board[x][y] == 2 || board[x][y] == 4) && (board[x + 1][y - 1] == 2 || board[x + 1][y - 1] == 4))
								m = 1;
							if ((board[x][y] == 2 || board[x][y] == 4) && board[x + 1][y - 1] == 0 && !m)
								return 1;
						}
						x++;
						y--;
					}
				}
			}
		}
	return 0;
}

bool check_fight_for_checker(vector <vector<int>>& board, bool move, int mouse_x, int mouse_y)
{
	int x, y, j, i;
	j = mouse_y;
	i = mouse_x;
	if (board[mouse_y][mouse_x] == 2 && !move)
	{
		if (mouse_x - 2 >= 0 && mouse_y + 2 < 8) //вниз влево
			if ((board[mouse_y + 1][mouse_x - 1] == 1 || board[mouse_y + 1][mouse_x - 1] == 3) && board[mouse_y + 2][mouse_x - 2] == 0)
				return 1;
		if (mouse_x + 2 < 8 && mouse_y + 2 < 8) //вниз вправо
			if ((board[mouse_y + 1][mouse_x + 1] == 1 || board[mouse_y + 1][mouse_x + 1] == 3) && board[mouse_y + 2][mouse_x + 2] == 0)
				return 1;
		if (mouse_x - 2 >= 0 && mouse_y - 2 >= 0) //вверх влево
			if ((board[mouse_y - 1][mouse_x - 1] == 1 || board[mouse_y - 1][mouse_x - 1] == 3) && board[mouse_y - 2][mouse_x - 2] == 0)
				return 1;
		if (mouse_x + 2 < 8 && mouse_y - 2 >= 0) //вверх вправо
			if ((board[mouse_y - 1][mouse_x + 1] == 1 || board[mouse_y - 1][mouse_x + 1] == 3) && board[mouse_y - 2][mouse_x + 2] == 0)
				return 1;
	}
	else if (board[mouse_y][mouse_x] == 4 && !move)
	{
		if (j - 1 >= 0 && i + 1 < 8) //вниз влево
		{
			x = j - 1;
			y = i + 1;
			bool m = 0;
			while (x >= 0 && y < 8)
			{
				if (x - 1 >= 0 && y + 1 < 8)
				{
					if (board[x][y] == 2 || board[x][y] == 4)
						m = 1;
					if ((board[x][y] == 1 || board[x][y] == 3) && board[x - 1][y + 1] == 0 && !m)
						return 1;
				}
				x--;
				y++;
			}
		}
		if (j + 1 < 8 && i + 1 < 8) //вниз вправо
		{
			x = j + 1;
			y = i + 1;
			bool m = 0;
			while (x < 8 && y < 8)
			{
				if (x + 1 < 8 && y + 1 < 8)
				{
					if (board[x][y] == 2 || board[x][y] == 4)
						m = 1;
					if ((board[x][y] == 1 || board[x][y] == 3) && board[x + 1][y + 1] == 0 && !m)
						return 1;
				}
				x++;
				y++;
			}
		}
		if (j - 1 >= 0 && i - 1 >= 0) //вверх влево
		{
			x = j - 1;
			y = i - 1;
			bool m = 0;
			while (x >= 0 && y >= 0)
			{
				if (x - 1 >= 0 && y - 1 >= 0)
				{
					if (board[x][y] == 2 || board[x][y] == 4)
						m = 1;
					if ((board[x][y] == 1 || board[x][y] == 3) && board[x - 1][y - 1] == 0 && !m)
						return 1;
				}
				x--;
				y--;
			}
		}
		if (j + 1 < 8 && i - 1 >= 0) //вверх вправо
		{
			x = j + 1;
			y = i - 1;
			bool m = 0;
			while (x < 8 && y >= 0)
			{
				if (x + 1 < 8 && y - 1 >= 0)
				{
					if (board[x][y] == 2 || board[x][y] == 4)
						m = 1;
					if ((board[x][y] == 1 || board[x][y] == 3) && board[x + 1][y - 1] == 0 && !m)
						return 1;
				}
				x++;
				y--;
			}
		}
	}
	else if (board[mouse_y][mouse_x] == 1 && move)
	{
		if (mouse_x - 2 >= 0 && mouse_y + 2 < 8) //вниз влево
			if ((board[mouse_y + 1][mouse_x - 1] == 2 || board[mouse_y + 1][mouse_x - 1] == 4) && board[mouse_y + 2][mouse_x - 2] == 0)
				return 1;
		if (mouse_x + 2 < 8 && mouse_y + 2 < 8) //вниз вправо
			if ((board[mouse_y + 1][mouse_x + 1] == 2 || board[mouse_y + 1][mouse_x + 1] == 4) && board[mouse_y + 2][mouse_x + 2] == 0)
				return 1;
		if (mouse_x - 2 >= 0 && mouse_y - 2 >= 0) //вверх влево
			if ((board[mouse_y - 1][mouse_x - 1] == 2 || board[mouse_y - 1][mouse_x - 1] == 4) && board[mouse_y - 2][mouse_x - 2] == 0)
				return 1;
		if (mouse_x + 2 < 8 && mouse_y - 2 >= 0) //вверх вправо
			if ((board[mouse_y - 1][mouse_x + 1] == 2 || board[mouse_y - 1][mouse_x + 1] == 4) && board[mouse_y - 2][mouse_x + 2] == 0)
				return 1;
	}
	else if (board[j][i] == 3 && move)
	{
		if (j - 1 >= 0 && i + 1 < 8) //вниз влево
		{
			x = j - 1;
			y = i + 1;
			bool m = 0;
			while (x >= 0 && y < 8)
			{
				if (x - 1 >= 0 && y + 1 < 8)
				{
					if (board[x][y] == 1 || board[x][y] == 3)
						m = 1;
					if ((board[x][y] == 2 || board[x][y] == 4) && board[x - 1][y + 1] == 0 && !m)
						return 1;
				}
				x--;
				y++;
			}
		}
		if (j + 1 < 8 && i + 1 < 8) //вниз вправо
		{
			x = j + 1;
			y = i + 1;
			bool m = 0;
			while (x < 8 && y < 8)
			{
				if (x + 1 < 8 && y + 1 < 8)
				{
					if (board[x][y] == 1 || board[x][y] == 3)
						m = 1;
					if ((board[x][y] == 2 || board[x][y] == 4) && board[x + 1][y + 1] == 0 && !m)
						return 1;
				}
				x++;
				y++;
			}
		}
		if (j - 1 >= 0 && i - 1 >= 0) //вверх влево
		{
			x = j - 1;
			y = i - 1;
			bool m = 0;
			while (x >= 0 && y >= 0)
			{
				if (x - 1 >= 0 && y - 1 >= 0)
				{
					if (board[x][y] == 1 || board[x][y] == 3)
						m = 1;
					if ((board[x][y] == 2 || board[x][y] == 4) && board[x - 1][y - 1] == 0 && !m)
						return 1;
				}
				x--;
				y--;
			}
		}
		if (j + 1 < 8 && i - 1 >= 0) //вверх вправо
		{
			x = j + 1;
			y = i - 1;
			bool m = 0;
			while (x < 8 && y >= 0)
			{
				if (x + 1 < 8 && y - 1 >= 0)
				{
					if (board[x][y] == 1 || board[x][y] == 3)
						m = 1;
					if ((board[x][y] == 2 || board[x][y] == 4) && board[x + 1][y - 1] == 0 && !m)
						return 1;
				}
				x++;
				y--;
			}
		}
	}
	return 0;
}


void check_queen(vector <vector<int>>& board, int mouse_x, int mouse_y)
{
	if (board[mouse_y][mouse_x] == 1 && mouse_y == 0)
		board[mouse_y][mouse_x] = 3;
	if (board[mouse_y][mouse_x] == 2 && mouse_y == 7)
		board[mouse_y][mouse_x] = 4;
}


int main()
{
	setlocale(LC_ALL, "RUS");
	RenderWindow window(VideoMode(1600, 1280), "Checkers");

	vector <vector <int> > board = {{0, 2, 0, 2, 0, 2, 0, 2},
									{2, 0, 2, 0, 2, 0, 2, 0},
									{0, 2, 0, 2, 0, 2, 0, 2},
									{0, 0, 0, 0, 0, 0, 0, 0}, 
									{0, 0, 0, 0, 0, 0, 0, 0}, 
									{1, 0, 1, 0, 1, 0, 1, 0},
									{0, 1, 0, 1, 0, 1, 0, 1},
									{1, 0, 1, 0, 1, 0, 1, 0}};
	bool board_drow = 1, move = 1, possibility_move = 0, fight = 0, w_win = 0, b_win = 0;
	const int size = 160;
	int mouse_x, mouse_y, last_x = -1, last_y = -1, count_black = 0, count_white = 0, per = 0;

	RectangleShape shape(Vector2f(size, size));
	Font font;

	font.loadFromFile("Images/font1.ttf");
	Text text("", font, 60);
	text.setFillColor(Color(255, 0, 0));
	text.setPosition(1285, 600);

	Text count_black_eat("", font, 60);
	count_black_eat.setFillColor(Color(255, 0, 0));
	count_black_eat.setPosition(1285, 1200);

	Text count_white_eat("", font, 60);
	count_white_eat.setFillColor(Color(255, 0, 0));
	count_white_eat.setPosition(1285, 50);

	Text black_eat("", font, 42);
	black_eat.setFillColor(Color(255, 0, 0));
	black_eat.setString(L"Съедено чёрных:");
	black_eat.setPosition(1285, 1150);

	Text white_eat("", font, 42);
	white_eat.setFillColor(Color(255, 0, 0));
	white_eat.setPosition(1285, 0);
	white_eat.setString(L"Съедено белых:");

	Text win("", font, 180);
	win.setFillColor(Color(255, 0, 0));
	win.setPosition(30, 460);

	Texture white_checker_txt, black_checker_txt, white_queen_txt, black_queen_txt;
	white_checker_txt.loadFromFile("Images/white_checker.png");
	black_checker_txt.loadFromFile("Images/black_checker.png");
	white_queen_txt.loadFromFile("Images/white_queen.png");
	black_queen_txt.loadFromFile("Images/black_queen.png");

	Sprite white_checker_spr, black_checker_spr, white_queen_spr, black_queen_spr;
	white_checker_spr.setTexture(white_checker_txt);
	black_checker_spr.setTexture(black_checker_txt);
	white_queen_spr.setTexture(white_queen_txt);
	black_queen_spr.setTexture(black_queen_txt);
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		fight = 0;
		fight = check_fight(board, move);
		if (event.type == Event::MouseButtonPressed)
			if (event.mouseButton.button == Mouse::Left && !w_win && !b_win)
				if (event.mouseButton.x > 0 && event.mouseButton.x <= 1280 && event.mouseButton.y > 0 && event.mouseButton.y <= 1280)
				{
					mouse_x = event.mouseButton.x / size;
					mouse_y = event.mouseButton.y / size;
					if (!fight)
					{
						if (move && (board[mouse_y][mouse_x] == 1 || board[mouse_y][mouse_x] == 3))
						{
							last_x = mouse_x;
							last_y = mouse_y;
						}
						else if (!move && (board[mouse_y][mouse_x] == 2 || board[mouse_y][mouse_x] == 4))
						{
							last_x = mouse_x;
							last_y = mouse_y;
						}
						else if (move && last_x != -1 && last_y != -1)
						{
							possibility_move = check_move(board, move, last_x, last_y, mouse_x, mouse_y);
							if (possibility_move)
							{
								per = board[last_y][last_x];
								board[last_y][last_x] = 0;
								board[mouse_y][mouse_x] = per;
								last_x = -1;
								last_y = -1;
								possibility_move = 0;
								move = 0;
								check_queen(board, mouse_x, mouse_y);
							}
						}
						else if (!move && last_x != -1 && last_y != -1)
						{
							possibility_move = check_move(board, move, last_x, last_y, mouse_x, mouse_y);
							if (possibility_move)
							{
								per = board[last_y][last_x];
								board[last_y][last_x] = 0;
								board[mouse_y][mouse_x] = per;
								last_x = -1;
								last_y = -1;
								possibility_move = 0;
								move = 1;
								check_queen(board, mouse_x, mouse_y);
							}
						}
					}
					if (fight)
					{
						if (move && (board[mouse_y][mouse_x] == 1 || board[mouse_y][mouse_x] == 3))
						{
							last_x = mouse_x;
							last_y = mouse_y;
						}
						else if (!move && (board[mouse_y][mouse_x] == 2 || board[mouse_y][mouse_x] == 4))
						{
							last_x = mouse_x;
							last_y = mouse_y;
						}
						else if (move && last_x != -1 && last_y != -1)
						{
							possibility_move = check_possibility_eat(board, move, last_x, last_y, mouse_x, mouse_y);
							if (possibility_move)
							{
								per = board[last_y][last_x];
								board[last_y][last_x] = 0;
								board[mouse_y][mouse_x] = per;
								last_x = -1;
								last_y = -1;
								possibility_move = 0;
								check_queen(board, mouse_x, mouse_y);
								if (!check_fight_for_checker(board, move, mouse_x, mouse_y))
									move = 0;
							}
						}
						else if (!move && last_x != -1 && last_y != -1)
						{
							possibility_move = check_possibility_eat(board, move, last_x, last_y, mouse_x, mouse_y);
							if (possibility_move)
							{
								per = board[last_y][last_x];
								board[last_y][last_x] = 0;
								board[mouse_y][mouse_x] = per;
								last_x = -1;
								last_y = -1;
								possibility_move = 0;
								check_queen(board, mouse_x, mouse_y);
								if (!check_fight_for_checker(board, move, mouse_x, mouse_y))
									move = 1;
							}
						}
					}
				}
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
			{
				if (i % 2 != 0)
				{
					if (board_drow)
						shape.setFillColor(Color(250, 235, 215));
					else
						shape.setFillColor(Color(205, 133, 63));
				}
				else
				{
					if (!board_drow)
						shape.setFillColor(Color(250, 235, 215));
					else
						shape.setFillColor(Color(205, 133, 63));
				}
				shape.setPosition(size * (j - 1), size * (i - 1));
				if (board_drow)
					board_drow = 0;
				else
					board_drow = 1;
				window.draw(shape);
			}
		for(int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 1)
				{
					white_checker_spr.setPosition(size * j + 5, size * i + 5);
					window.draw(white_checker_spr);
					count_white += 1;
				}
				else if (board[i][j] == 2)
				{
					black_checker_spr.setPosition(size * j + 5, size * i + 5);
					window.draw(black_checker_spr);
					count_black += 1;
				}
				else if (board[i][j] == 3)
				{
					white_queen_spr.setPosition(size* j + 5, size* i + 5);
					window.draw(white_queen_spr);
					count_white += 1;
				}
				else if (board[i][j] == 4)
				{
					black_queen_spr.setPosition(size * j + 5, size * i + 5);
					window.draw(black_queen_spr);
					count_black += 1;
				}
			}
		if (move)
			text.setString(L"Ход белых");
		else
			text.setString(L"Ход чёрных");
		if (count_white == 0)
			w_win = 1;
		else if (count_black == 0)
			b_win = 1;
		count_white_eat.setString(to_string(12 - count_white));
		count_black_eat.setString(to_string(12 - count_black));
		if (!b_win && !w_win)
			window.draw(text);
		window.draw(count_black_eat);
		window.draw(count_white_eat);
		window.draw(black_eat);
		window.draw(white_eat);
		if (w_win)
		{
			win.setString(L"Победа чёрных");
			window.draw(win);
		}
		else if (b_win)
		{
			win.setString(L"Победа белых");
			window.draw(win);
		}
		window.display();
		count_white = 0;
		count_black = 0;
	}

	return 0;
}