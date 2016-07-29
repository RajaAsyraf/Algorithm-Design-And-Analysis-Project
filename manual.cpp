#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

int num = 10;	
int randlot;
int a[10];
void merge(int low, int mid, int high){
    int h,i,j,b[num],k;
    h=low;
    i=low;
    j=mid+1;

    while((h<=mid)&&(j<=high)){
        if(a[h]<=a[j]){
            b[i] = a[h];
            h++;
        }
        else{
            b[i]=a[j];
            j++;
        }
        i++;
    }

    if(h>mid){
        for(k=j;k<=high;k++){
            b[i]=a[k];
            i++;
        }
    }
    else{
        for(k=h;k<=mid;k++){
            b[i]=a[k];
            i++;
        }
    }

    for(k=low;k<=high;k++){
        a[k]=b[k];
    }
}

void mergeSort(int low, int high)
{
    int mid;
    if (low < high){
        mid = (low + high)/2;
        mergeSort(low,mid);
        mergeSort(mid+1,high);
        merge(low,mid,high);
    }
}


void bucketSort( int a[], int n)
{
    int m = 10 + 1;
    int buckets[m];
    for(int i=0;i<m;i++){
        buckets[i] = 0;
    }

    for(int i=0;i<n;i++){
        buckets[a[i]]++;
    }

    for(int i=0,j=0;j<m;j++){
        for(int k = buckets[j];k>0;k--){
            a[i++] = j;
        }
    }
}

int main()
{
    system("cls");
	cout << endl;
	cout<<"                     ========Merge Sort & Bucket Sort ==========" << endl;
    cout<< endl;
	cout << "Please insert 10 number:" << endl;
	//srand ( time(NULL) );
	//for(int i=0; i<num; i++){
	//	randlot = rand() % 1000 + 1;
    //    a[i] = randlot;
    //}
	for (int i=0; i<num; i++){
		cin >> a[i];
	}
	
	int a2[num];
	for(int i=0;i<num;i++){
        a2[i] = a[i];
    }
	for(int i=0; i<num; i++) {
		cout << a[i] << ", ";
		//cout << i+1  << ". " << a[i] << endl; 
	}
	
	cout << endl;
	system("pause");
	cout << endl;
	cout<<"                         ========Merge Sort Process ==========" << endl;
    cout<< endl;
	clock_t start1;
	start1 = clock();
	mergeSort(0,num);
    cout<<endl;
    cout<<"Sorted elements using Merge Sort: " << endl;
    cout << endl;

    for(int i=0;i<=num;i++)
    {
		cout << a[i] << ", ";
		//cout << i+1  << ". " << a[i] << endl; 
    }
	cout << endl << endl;
	cout << "Time taken: " << (clock() - start1) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
	cout << endl << endl;
	
	system("pause");
	cout << endl;
	cout << "                         ========Bucket Sort Process ==========" << endl;
	cout << endl;
	int input[num];
	for(int i=0;i<num;i++){
        input[i] = a2[i];
    }
	int n = sizeof(input)/sizeof(input[0]);
	clock_t start2;
	start2 = clock();
	bucketSort(input,n);
    cout << "Sorted elements using Bucket Sort : " << endl;
    for (int i = 0; i <num; ++i){
        cout << input[i] << ", ";
		//cout << i+1  << ". " << input[i] << endl; 
    }
	cout << endl << endl;
	cout << "Time taken: " << (clock() - start2) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
	
	
	
	
	
}