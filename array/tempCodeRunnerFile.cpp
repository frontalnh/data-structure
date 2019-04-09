
    helper->startMeasure();
    int arr2[] = {1, 2, 3};
    for (int i = 0; i < 2; i++)
    {
        arr2[i] = arr2[i + 1];
    }
    helper->endMeasure("shift by 2");