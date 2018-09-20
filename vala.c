#include <stdio.h>

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[n];
		int i;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int height[n];
		for(i=0;i<n;i++){
			height[i] = 0;
		}
		int flag = 1;
		for(i=n-1;i>=0;i--){
			int left = 2*i+1;
			int right = 2*i+2;
			int h = 0;
			if(a[i] != -1){
				if(left < n && right < n){
					if(height[left] >= height[right]){
						height[i] = 1 + height[left];
					}else{
						height[i] = 1 + height[right];
					}
					if(height[left] - height[right] > 1 || height[right] - height[left] > 1){
						flag = 0;
						break;
					}
				}else{
					if(left < n){
						height[i] = 1 + height[left];
					}else{
						height[i] = 1;
					}
				}
			}
		}
		if(flag){
			printf("T\n");
		}else{
			printf("F\n");
		}
	}
	return 0;
}
