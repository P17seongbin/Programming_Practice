//KOI 2003 - 고등부 C - 직각다각형의 면적 구하기
//Plain Sweeping
#include<cstdio>
#define MAX_POS 10000
using namespace std;

class cell_datum
{
public:
	bool colored, u, d, l, r;
} field[MAX_POS+1][MAX_POS+1];

int mx, my;
int minx, miny;
int inline max(int l, int r) { return (l > r) ? l : r; }
int inline min(int l, int r) { return (l < r) ? l : r; }

int coloring(int x,int y)
{
	int area = 1;
	if (x < 0 || y < 0)
		return 0;
	if (x < minx || y < minx)
		return (mx * my + 1) * (-1);
	if (field[x][y].colored)
		return 0;
	if (x > mx || y > my)
		return 0;

	field[x][y].colored = true;
	if (field[x][y].u) area += coloring(x, y - 1);
	if (field[x][y].d) area += coloring(x, y + 1);
	if (field[x][y].l) area += coloring(x - 1, y);
	if (field[x][y].r) area += coloring(x + 1, y);
	return area;

}


int main()
{
	printf("%d", sizeof(cell_datum));
	cell_datum t;
	t.colored = false;
	t.u = t.d = t.l = t.r = true;
	for (int i = 0; i <=  MAX_POS; i++)
	{
		for (int j = 0; j <= MAX_POS; j++)
		{
			field[i][j] = t;
		}
	}
	//캐시 초기화
	int n;
	int fx, fy;//first
	int px, py;//previous

	scanf("%d", &n);
	scanf("%d %d", &fx, &fy);
	px = fx;
	py = fy;
	mx = fx;
	my = fy;//max
	minx = fx;
	miny = fy;//min
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if (x > mx) mx = x;
		if (y > my) my = y;
		if (x < minx) minx = x;
		if (y < miny) miny = y;
		if (x == px)
		{
			for (int j = min(y, py); j < max(y, py); j++)
			{
				field[x][j].l = false;
				if (x != 0)
					field[x - 1][j].r = false;
			}
		}
		else
		{
			for (int j = min(x, px); j < max(x, px); j++)
			{
				field[j][y].u = false;
				if (y != 0)
					field[j][y - 1].d = false;
			}
		}
		px = x;
		py = y;
	}

	if (fx == px)
	{
		for (int j = min(fy, py); j < max(fy, py); j++)
		{
			field[fx][j].l = false;
			if (fx != 0)
				field[fx - 1][j].r = false;
		}
	}
	else
	{
		for (int j = min(fx, px); j < max(fx, px); j++)
		{
			field[j][fy].u = false;
			if (fy != 0)
				field[j][fy - 1].d = false;
		}
	}
	//선 데이터를 반영

	//컬러링(+카운팅) 시작
	int max_area = 0;
	for (int i = 0; i <= mx; i++)
	{
		for (int j = 0; j <= my; j++)
		{
			if (field[i][j].colored)
				continue;
			if (field[i][j].u + field[i][j].d + field[i][j].l + field[i][j].r <= 2)
			{
				int area = coloring(i,j);
				if (area > max_area) max_area = area;
			}
		}
	}
	printf("%d", max_area);
}
