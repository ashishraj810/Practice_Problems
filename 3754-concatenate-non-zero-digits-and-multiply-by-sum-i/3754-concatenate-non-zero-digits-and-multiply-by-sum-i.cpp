class Solution {
public:
    long long sumAndMultiply(int n) {
      string s = to_string(n);
      string x = "";
      int sum = 0;

      for(char ch : s)
      {
        if(ch != '0')
        x += ch;
      }

      if (x.empty())
      return 0;
      
      int new_n = stoi(x);
      int p = new_n;

      while(new_n != 0)
      {
        int r = new_n % 10;
        sum += r;

        //update x
        new_n = new_n / 10; 
      }
      long long answer = 1LL * p * sum;
      return answer;   
    }
    
};