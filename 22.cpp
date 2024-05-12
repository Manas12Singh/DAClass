struct Job {
    char id;
    int deadline, profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void JobScheduling(Job arr[], int n) {
    sort(arr, arr+n, comparison);

    vector<int> result(n);
    vector<bool> slot(n);

    for (int i=0; i<n; i++) {
        for (int j=min(n, arr[i].deadline)-1; j>=0; j--) {
            if (slot[j]==false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i=0; i<n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
}
