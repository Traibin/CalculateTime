#include<iostream>
using namespace std;
class TrainTrip;
class Clock
{
private:
	int H, M, S;
public:
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
	void SetTime(int H = 0, int M = 0, int S = 0)
	{
		this->H = H;
		this->M = M;
		this->S = S;
	}
	Clock(int H = 0, int M = 0, int S = 0)
	{
		this->H = H;
		this->M = M;
		this->S = S;
	}
	friend class TrainTrip;//clock����Ԫ��
};
class TrainTrip
{
private:
	char TrainNo[20];//����
    Clock StartTime;//����ʱ��
	Clock EndTime;//����ʱ��
public:
	TrainTrip(const char N[20], Clock S, Clock E)//���캯��
	{
		strcpy_s(TrainNo, strlen(TrainNo) + 1, N);
		StartTime = S;
		EndTime = E;
	}
	Clock TrainTime()
	{

		int tH, tM, tS;//��ʱ����ʱ����
		int carry = 0;//��λ
		Clock tTime;//��ʱ����ʱ��
		(tS = EndTime.S - StartTime.S) > 0 ? carry = 0 : tS += 60, carry = 1;
		(tM = EndTime.M - StartTime.M - carry) > 0 ? carry = 0 : tM += 60, carry = 1;
		(tH = EndTime.H - StartTime.H - carry) > 0 ? carry = 0 : tH += 24;
		tTime.SetTime(tH, tM, tS);
		return tTime;
	}
};
int main()
{
	Clock C1(8, 10, 10), C2(6, 1, 2);
	Clock C3;
	TrainTrip T1("K16", C1, C2);
	C3 = T1.TrainTime();
	C1.ShowTime();
	C2.ShowTime();
	C3.ShowTime();
	
	system("pause");
	return 0;
}