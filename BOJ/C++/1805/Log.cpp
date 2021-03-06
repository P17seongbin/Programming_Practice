// Log.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include<iostream>
#include<vector>


using namespace std;

class node
{
private:
	int index;//마을 번호
	int value;//통나무 양
	int total_flow;//이 마을에 도달하기 까지 지불한 총 Cost
	int total_log;//이 마을에 도달한 총 통나무의 양(이 마을에 있는 통나무는 제외)
	int next_node;//-1이면 다음 노드가 없다는 뜻(목공소 설치됨)이다.
	int weight;//다음 마을로 가는데 드는 비용
	vector<int> prv_node;//이 마을과 연결된 이전 마을들

	node()//기본 생성자 차단
	{

	}

public:
	node(int i,int v=0,int t=0,int n=-1,int w=0)//index, weight, value는 처음 설정하고 바뀌지 않는다.
	{
		index = i;
		value = v;
		total_flow = total_log = t;
		next_node = n;
		weight = w;
	}
	int Get_Delta()
	{
		return (total_log + value) * weight; 
	}
	int Get_TotalLog()
	{
		return total_log;
	}
	int Get_CurrentLog()
	{
		return value;
	}
	void Set_TotalLog(int v)
	{
		total_log = v;
	}
	int Get_Next()
	{
		return next_node;
	}
	int Get_Cur_Flow()
	{
		return total_flow; 
	}
	int Get_Flow()//이 노드의 다음 노드에 인가될 Flow값을 리턴( (이전 Flow + (현재 Node의 통나무 양) * (현재 Node의 Weight))
	{
		return total_flow + ((value+total_log)* weight);
	}
	void Set_Flow(int v)//Flow를 받아온다.
	{
		total_flow = v;
	}
	void Deploy_Carpenter()//목공소 설치(다음 노드는 없어요)
	{
		next_node = -1;
		weight = 0;
	}
	bool Is_Carpenter_Deployed()//목공소가 설치되었는가?(Next_Node가 -1인가?)
	{
		return next_node == -1;
	}
	void Add_Prv(int v)
	{
		prv_node.push_back(v);
	}
	vector<int> Get_Prv()//전에 연결된 노드를 리턴한다.
	{
		return prv_node;
	}
	
};

vector<node> town;
int Cal_Totalflow(int n);

int main()
{
	int n, k;
	cin >> n >> k;

	//왕국 노드(0번 노드) 추가
	node te(0, 0, 0, -1, 0);
	town.push_back(te);
	//노드 정보 추가
	for (int i = 1; i <= n; i++)
	{
		int amount, next, weight;
		cin >> amount >> next >> weight;
		node t(i, amount, 0, next, weight);
		town.push_back(t);
	}
	//노드 연결(Prv_node 업데이트)
	for (int i = 0; i <= n; i++)
	{
		int t = town[i].Get_Next();
		if(t != -1)
		town[t].Add_Prv(i);
	}
	for (int z = 0; z < k; z++)
	{

		//1. 모든 Tree를 역추적하면서 모든 Leaf node에 도달한다.
		//2. Leaf Node에서 flow를 따라 내려오면서 Total cost를 계산한다.
		Cal_Totalflow(0);

		int max = -1, max_index = -1;
		//3. 모든 Node를 Index를 기준으로 순회하면서 (Total Log * Weight)이 가장 큰 Node를 찾는다.s
		for (int i = 0; i <= n; i++)
		{
			int t_cm = town[i].Get_Delta();
			if (max < t_cm)
			{
				max_index = i;
				max = t_cm;
			}

		}
		town[max_index].Deploy_Carpenter();
		//4. 그 Node에 목공소를 설치한다.
		//5. k회 반복
	}
	Cal_Totalflow(0);
	//노드를 순회하면서 Next Node가 -1인(Subtree의 Root인) Node들의 Total flow를 다 더해준다.
	int final_value = 0;
	for (int i = 0; i <= n; i++)
	{
		if (town[i].Get_Next() == -1)
			final_value += town[i].Get_Cur_Flow();
	}
	cout << final_value;
}

//Index가 n인 Node의 Total Flow를 계산한다.(그리고 리턴
int Cal_Totalflow(int n)
{
	vector<int> temp_prv = town[n].Get_Prv();

	int v = 0, t = temp_prv.size();
	int tl = 0;
	//모든 Prv_Node의 Flow를 받아온다.
	for (int i = 0; i < t; i++)
	{
		int Tf = Cal_Totalflow(temp_prv[i]);
		v += Tf;
		if (Tf != 0)
		{
			tl += town[temp_prv[i]].Get_TotalLog() + town[temp_prv[i]].Get_CurrentLog();
		}
	}
	town[n].Set_TotalLog(tl);
	town[n].Set_Flow(v);

	if (town[n].Is_Carpenter_Deployed())
		return 0;
	else
		return town[n].Get_Flow();
}


