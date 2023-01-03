//Quick Sort

#include<iostream>
using namespace std;

int partition(int salary[], int lb, int ub)
{
    int pivot = salary[lb], count = 0;
    for (int i = lb + 1; i <= ub; i++)
    {
        if (salary[i] <= pivot)
        count++;
    }
    int pindex = lb + count;
    swap(salary[pindex], salary[lb]);
    int start = lb, end = ub;
    while (start < pindex && end > pindex)
    {
        while (salary[start] <= pivot)
        start++;

        while (salary[end] > pivot)
        end--;

        if (start < pindex && end > pindex)
        swap(salary[start++], salary[end--]);
    }
    return pindex;
}

void qcksort(int salary[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(salary, lb, ub);
        qcksort(salary, lb, loc - 1);
        qcksort(salary, loc + 1, ub);
    }
    else
    return;
}

int main()
{
    int salary[10], lb, ub, n, i;
    cout << "\nEnter number of employees : ";
    cin >> n;
    cout << "\nEnter the Salaries of Employees :\n";
    for (i = 0; i < n; i++)
    cin >> salary[i];
    qcksort(salary, 0, n - 1);
    cout<<"\nTop 5 highest salaries are :\n";
    for (i = n-1; i >=n-5; i--)
    cout << salary[i] << " ";
    return 0;
}
