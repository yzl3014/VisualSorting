/*�����㷨��ʾ v0.1-2022.2.21[ð������] by Ԭ�Ӿ�(���д����Ϊ���˱�д)*/		
#include <stdio.h>
#include <graphics.h>
using namespace std;
int inOperationNums[32];//���ڲ��������ֽ����ֲ�ͬ����ɫ�����Ӿ�Ч��
int width =5, bkwidth = 800, num = bkwidth / width - 10,operatingNum;
//��һ�У��ֱ�Ϊ���ӿ�ȣ������Ⱥ���������(***����������������ʵ������һ��***)
int height[1024];///ע���޸�����Ĳ�����1024�Ͳ�๻��
void refresh()//ˢ��һ����Ļ
{
	//printf("ˢ��\n");
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
void makeColumn()//��������
{
	cleanShuZu();
	setfillcolor(RGB(0, 0, 0));
	setlinecolor(RGB(0, 0, 0));
	for (int i = 0; i <= num; i++)
	{
		refresh();
		int sjnum = rand() % bkwidth;
		fillrectangle((i - 1) * width, sjnum, i * width, 500);
		/*���Ͻ�x, y; ���Ͻ�x, y*/
		height[i] = bkwidth - sjnum;//��ΪeasyX������ϵ�ǵ��ŵģ���������Խ�ߵ�numԽС
		refresh();
		printf("%d\n", sjnum);
		Sleep(2000);
	}
}
void sortNum()
{
	refresh();
	/// �����Ǿ������ڵ�ð�������㷨�����Ը���Ϊ�����㷨
	int temp;//����ʱ��ʱ����
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < (num-i); j++)
		/*�����num - i����Ϊ���������forѭ����һ����һ�������ˣ���������һ����
		��Ϊ�������������󣬾ͻ�һֱ���
		*/
		{
			operatingNum = height[j];
			refresh();
			if (height[j] < height[j + 1])//�����j���ȵ�(j+1)��С���ͻ���λ��(�Ӵ�С����)
			{
				temp = height[j];//һ���򵥵�λ�û���
				height[j] = height[j + 1];
				height[j + 1] = temp;
			}
			if (height[j] > height[j + 1])
			{
				continue;
			}
		}
	}
	//�������˽���
	//������ÿ�����Ӷ���ʾ��ɫ��ֻ��Ϊ���Ӿ�Ч���ã���Ҳ�����˵���
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

	initgraph(bkwidth, 500, SHOWCONSOLE);//����
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