#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node
{
	int address, data, next;
	int order;// �ڵ������е�λ��
}node[maxn];
bool cmp(Node a, Node b){
	if (a.order == -1 || b.order == -1){
		return a.order > b.order;
	}
	else{
		return a.order < b.order;
	}
}


void start(){
	for (int i = 0; i < maxn; i++)
	{
		node[i].order = -1;
	}
	int begin, n, K, address;
	scanf("%d%d%d", &begin,&n,&K);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int p = begin, count = 0;
	while (p!=-1)
	{
		node[p].order = count++;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	n = count;
	for (int i = 0; i < n/K; i++)
	{
		for (int j = (i + 1)*K - 1; j>i*K; j--){
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
		}
		printf("%05d %d ", node[i*K].address, node[i*K].data);
		if (i < n / K - 1)// �������һ�飬��ָ����һ������һ���ڵ�
		{
			printf("%05d\n", node[(i + 2)*K - 1].address);
		}
		else//  �����һ��
		{
			if (n%K == 0){// ǡ�������һ���ڵ� ���-1
				printf("-1\n");
			}
			else{//  ʣ�µĲ��ְ���ԭ�ȵ�˳�����
				printf("%05d\n", node[(i +1)*K ].address);
				for (int  i =n/K*K; i < n; i++)
				{
					printf("%05d %d ", node[i].address, node[i].data);
					if (i<n-1)
					{
						printf("%05d\n",  node[i+1].address);
					}
					else{
						printf("-1\n");
					}
				}
			}
		}
	}

}