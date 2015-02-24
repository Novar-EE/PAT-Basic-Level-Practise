#include <cstdio>
#include <cstring>
using namespace std;


int x1 [ 110 ], x2[ 110 ], tar[ 110 ], buf[ 220 ], n;

void scan( int& x )
{
    char c;
    while( c = getchar(), c < '0' || c > '9' );
    x = c - '0';
    while( c = getchar(), c >= '0' && c <= '9' ) x = x * 10 + c - '0';
}

void Merge_Sort( int arr[], int n )
{
    int flag = 0, j;
    int step, lbe, led, rbe, red;

    for( step = 1; step < n; step <<= 1 )
    {
        for( lbe = 0; lbe < n - step; lbe = red + 1 )
        {
            rbe = lbe + step;
            led = rbe - 1;
            red = led + step;
            if( red > n - 1 )
                red = n - 1;
            int k = 0;
            memset( buf, 0, sizeof(buf) );
            
            while( lbe <= led && rbe <= red )
            {
                if( arr[lbe] < arr[rbe] )
                    buf[k++] = arr[lbe++];
                else
                    buf[k++] = arr[rbe++];
            }
            while( lbe <= led )    buf[k++] = arr[lbe++];
            while( rbe <= red )    buf[k++] = arr[rbe++];
            while( k > 0 )        arr[ --rbe ] = buf[ --k ];
        }
        if( flag )
        {
            printf( "Merge Sort\n" );
            for( j = 0; j < n; ++j )
            {
                if( j != 0 ) putchar( ' ' );
                printf( "%d", arr[j] );
            }
            putchar( '\n' );
            return;
        }
        for( j = 0; j < n; ++j )
        {
            if( arr[j] != tar[j] )
                break;
        }
        if( j == n )
            flag = 1;
    }
}

bool Insert_Sort( int arr[], int n )
{
    int b, e, t, i, flag = 0;
    
    for( b = 1; b < n; ++b )
    {
        t = arr[b];
        e = b;
        while( e > 0 && arr[ e - 1 ] > t )
        {
            arr[ e ] = arr[ e - 1 ];
            --e;
        }
        arr[ e ] = t;    
        
        for( i = 0; i < n; ++i )
        {
            if( arr[i] != tar[i] )
                break;
        }
        if( flag )
        {
            printf( "Insertion Sort\n" );
            for( i = 0; i < n; ++ i )
            {
                if( i != 0 )    putchar( ' ' );
                printf( "%d", arr[i] );
            }
            putchar( '\n' );
            return true;
        }
        if( i == n )
            flag = 1;
    }
    return false;
}


int main()
{
    scan( n );
    for( int i = 0; i < n; ++i )
    {
        scan( x1[i] );
        x2[i] = x1[i];
    }
    for( int i = 0; i < n; ++i )
        scan( tar[i] );
    if( !Insert_Sort( x1, n ) )
        Merge_Sort( x2, n );
        
    return 0;
}
