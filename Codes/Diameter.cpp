pair<int,int> bfs(int st)
{
     memset(low,0,sizeof(low));
     //int last = st;
     low[st] = 0;
     queue<int> q;
     q.push(st);
     int last = st;
     while(!q.empty())
     {
          last = q.front();
          q.pop();
          for(auto i:tree[last])
          {
               if(i==st||low[i]!=0)
                    continue;
               low[i] = low[last]+1;
               q.push(i);
          }
     }
     return {last,low[last]};
}


/*
  pr p1  = bfs(start);
  pr p2 = bfs(p1.ff);
  cout<<p2.ss<<endl;
*/
