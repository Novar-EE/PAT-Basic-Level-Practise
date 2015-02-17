#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long x[ 100010 ], M, p;
int n, flag = 0, t, maxx = 0;

int main()
{
    scanf( "%d %lld", &n, &p );
    for( int i = 0; i < n; ++i )
        scanf( "%lld", &x[i] );    
    sort( x, x + n );
    for( int i = 0; i < n; ++i )
    {
    	// 直接搜索上一次循环得到的长度 
        for( int j = i + maxx - 1; j < n; ++j )
        {
            if( j < 0 )    continue;
            if( x[i]*p < x[j] )    break;
            if( j - i + 1 > maxx )
                maxx = j - i + 1;
        }
    }
    printf( "%d\n", maxx );
    return 0;
}