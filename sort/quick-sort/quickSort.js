function quickSort(arr) {
  if (arr.length < 2) return arr; // 모든 재귀함수에는 종료지점을 명시하는 것이 매우매우 중요하다.

  let pivotIndex = 0;
  let pivot = arr[pivotIndex];
  const less = [];
  const greater = [];
  for (let i = 0; i < arr.length; i++) {
    if (i != pivotIndex) {
      arr[i] > pivot ? greater.push(arr[i]) : less.push(arr[i]);
    }
  }

  return [...quickSort(less), pivot, ...quickSort(greater)];
}
const arr = [4, 5, 7, 3, 1, 45, 7, 6];

console.log(quickSort(arr));
