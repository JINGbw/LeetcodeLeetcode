class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1 )
            return 0;
// - 题目： 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。如果你最多只允许完成**一笔交易**（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。注意你不能在买入股票前卖出股票。
//- 思路：使用一个变量记录第i天的最低买入价格，一个变量记录第i天可获得的最大利润。
        //使用一个数存放当前可以获得的最大利润
        int profit = 0 ;//第0天可获得的最大利润
        int minprice = prices[0];//第0天的最低买入价格 
        for(int i = 1 ;i<prices.size() ; i++){
          minprice = min(prices[i],minprice);//第i天的最低买入价格
          profit = max(profit,prices[i] - minprice);//第i天的获利
        }
        return profit;
}
};
