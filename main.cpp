/*排序算法演示 v0.1-2022.2.21[冒泡排序] by 袁子钧(所有代码均为本人编写)*/		
#include <stdio.h>
#include <graphics.h>
using namespace std;
int inOperationNums[32];//正在操作的数字将呈现不同的颜色提升视觉效果
int width =5, bkwidth = 800, num = bkwidth / width - 10,operatingNum;
//上一行：分别为柱子宽度，画面宽度和柱子总数(***柱子总数可能与真实数量不一致***)
int height[1024];///注意修改这里的参数，1024就差不多够了
void refresh()//刷新一下屏幕
{
	//printf("刷新\n");
	cleardevice();
	setfillcolor(RGB(255, 255, 255));
	setlinecolor(RGB(0, 0, 0));
	for (int i = 0; i <= num; i++)
	{
		if (operatingNum == height[i])
		{
			setfillcolor(RGB(255,0, 0));
			operatingNum = -1;
		}
		else
		{
			setfillcolor(RGB(255, 255, 255));
		}
		fillrectangle((i - 1) * width, height[i], i * width, 500);
	}
	FlushBatchDraw();
}
void cleanShuZu()
{
	for (int i = 0; i <= num; i++)
	{
		height[i] = '\0';
	}
}
void makeColumn()//制造柱子
{
	cleanShuZu();
	setfillcolor(RGB(0, 0, 0));
	setlinecolor(RGB(0, 0, 0));
	for (int i = 0; i <= num; i++)
	{
		refresh();
		int sjnum = rand() % bkwidth;
		fillrectangle((i - 1) * width, sjnum, i * width, 500);
		/*左上角x, y; 右上角x, y*/
		height[i] = bkwidth - sjnum;//因为easyX的坐标系是倒着的，所以柱子越高的num越小
		refresh();
		printf("%d\n", sjnum);
		Sleep(2000);
	}
}
void sortNum()
{
	refresh();
	/// 下面是绝对正宗的冒泡排序算法！可以更改为其他算法
	int temp;//互换时临时调用
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < (num-i); j++)
		/*上面的num - i是因为，经过这次for循环后一定有一个排完了，即最大的那一个。
		因为它比所有数都大，就会一直向后
		*/
		{
			operatingNum = height[j];
			refresh();
			if (height[j] < height[j + 1])//如果第j个比第(j+1)个小，就互换位置(从大到小排序)
			{
				temp = height[j];//一个简单的位置互换
				height[j] = height[j + 1];
				height[j + 1] = temp;
			}
			if (height[j] > height[j + 1])
			{
				continue;
			}
		}
	}
	//排序至此结束
	//下面让每根柱子都显示绿色。只是为了视觉效果好，但也方便了调试
	setfillcolor(RGB(0, 255, 0));
	setlinecolor(RGB(0,0,0));
	for (int i = 0; i <= num; i++)
	{
		fillrectangle((i - 1) * width, height[i]-2, i * width, 500);
		FlushBatchDraw();
		Sleep(10);
	}
	printf("sort ok.\n");
	Sleep(2000);
}
int main()
{

	initgraph(bkwidth, 500, SHOWCONSOLE);//宽，高
	setbkcolor(RGB(0, 0, 0));
	BeginBatchDraw();
	while (1)
	{
		cleardevice();
		makeColumn();
		printf("MAKE OK!\n");
		sortNum();
		FlushBatchDraw();
		printf("--------------------------------------\n");
	}
	return 0;
}