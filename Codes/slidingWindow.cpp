deque<pair<int, int>> q;
 
void del()
{
	while (!q.empty())
	{
		q.pop_back();
	}
}
 
void insertion(pair<int, int> p)
{
	while (!q.empty())
	{
		pair<int, int> lst = q.back();
		if (lst.first >= p.first)
		{
			q.push_back(p);
			return;
		}
		else
		{
			q.pop_back();
		}
	}
 
	q.push_back(p);
}
 
int getMax(int j)
{
	int per = j - k + 1;
 
	while (q.front().second < per)
	{
		// if(j==4)
		// 	cout << "popping "<<" "<<q.front().second<<endl;
		q.pop_front();
	}
 
	return q.front().first;
}