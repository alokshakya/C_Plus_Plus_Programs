        #include<iostream>
        #include<string.h>
        #include<limits.h>
        #include<vector>
        #include<algorithm>
        #include<queue>
        #include<string>
        #include<math.h>
        #include<set>
        #include<stack>
        using namespace std;

        int root(int* array,int x)
        {
        	while(array[x] != x)
        	{
        		array[x] = array[array[x]];
        		x = array[x];
			}
			return x;
		}

        void dounion(int* array, int a, int b)
        {
        	int p = root(array,a);
        	int q = root(array,b);

        	if(p != q)
        	array[p] = array[q];
		}

        int main()
        {
                int n,d;
                cin>>n>>d;

                int* array = new int[n+1];

                for(auto i = 1; i <= n; i++)
                {
                	array[i] = i;
				}

				int operation;

				while(d--)
				{
					cin>>operation;

					switch(operation)
					{
						case 1:
							{
								int a,b;
								cin>>a>>b;
								dounion(array,a,b);
							}
						break;

						case 2:
							{
								int a;
								cin>>a;
								int aowner = root(array,a);
								if(aowner != a)
								array[aowner] = a;
								array[a] = a;
							}
						break;

						case 3:
							{
								int a;
								cin>>a;
								cout<<root(array,a)<<endl;
							}
						break;
					}
				}

                return 0;
        }
