#include<iostream>
using namespace std;

void findBuySellIndexForMaxProfit(int A[], int length)
{
  int buy = 0;
  int sell = 0;
  int profit = 0;
  int maxBuy = buy;
  int maxSell = sell;
  int maxProfit = profit;

  for(int i=1; i<length; i++)
  {
    sell = i;
    profit = A[sell] - A[buy];

    if(profit > maxProfit)
    {
      maxBuy = buy;
      maxSell = sell;
      maxProfit = profit;
    }

    if(profit < 0)
    {
      buy = i;
      sell = i;
      profit = 0;
    }

  }

cout<<"maxBuy:- "<<A[maxBuy]<<" maxSell:- "<<A[maxSell]<<endl;

}


int main()
{
  int A[] = {2,4,5,3,5,7,8,3,1};
  findBuySellIndexForMaxProfit(A, 9);
}
