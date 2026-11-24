// Tests for a selection of the solutions in Array/ and Hashing/.
//
// Every solution is a stand-alone .cpp file (some have their own demo main()),
// so each one is included here unchanged inside its own namespace, with its
// main() renamed. Nothing in a solution file has to change to be tested.
//
// Run from the repository root:
//   g++ -std=c++17 tests/solutions_tests.cpp -o tests/solutions_tests.out && ./tests/solutions_tests.out
//
// Every standard header used by the solutions has to be included here first,
// so that their own #include lines do nothing once inside a namespace.

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define main solutionDemoMain

// A real main() may end without "return 0;". Renamed, such a function would
// draw a warning although it is never called here.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

// Array/Basic Array DS
namespace alternate {
#include "../Array/Basic Array DS/Alternate Elements of an Array.cpp"
}
namespace leadersInArray {
#include "../Array/Basic Array DS/Leaders In an Array.cpp"
}
namespace mergeSorted {
#include "../Array/Basic Array DS/Merge Two Sorted Array.cpp"
}
namespace minCost {
#include "../Array/Basic Array DS/Minimum cost to make array size 1 by removing larger of pairs.cpp"
}
namespace moveZeros {
#include "../Array/Basic Array DS/Move All Zero to end of array.cpp"
}
namespace removeDup {
#include "../Array/Basic Array DS/Remove Duplicate From Sorted Array.cpp"
}
namespace minIncrements {
#include "../Array/Basic Array DS/min Increments to make equal.cpp"
}

// Array/EASY
namespace chocolate {
#include "../Array/EASY/Chocolate Distribution Problem.cpp"
}
namespace dupWithinK {
#include "../Array/EASY/Duplicate within k distance in an array.cpp"
}
namespace equilibrium {
#include "../Array/EASY/Equilibrium Index.cpp"
}
namespace missingNumber {
#include "../Array/EASY/FInd The Missing Number.cpp"
}
namespace intersectionSorted {
#include "../Array/EASY/Intersection of Two Sorted Arrays.cpp"
}
namespace intersectionUnsorted {
#include "../Array/EASY/Intersection of two arrays.cpp"
}
namespace maxProductSubarray {
#include "../Array/EASY/Maximum Product Subarray.cpp"
}
namespace repeatedConcat {
#include "../Array/EASY/Maximum subarray sum in an array created after repeated concatenation.cpp"
}
namespace missingRepeating {
#include "../Array/EASY/Missing and Repeating in an Array.cpp"
}
namespace onlyRepeating {
#include "../Array/EASY/Only Repeating Form 1 To n-1.cpp"
}
namespace posNeg {
#include "../Array/EASY/Rearrange positive and negative numbers wiht constant extra space.cpp"
}
namespace segregate01 {
#include "../Array/EASY/Segregate 0s and 1s in an array.cpp"
}
namespace wave {
#include "../Array/EASY/Sort an array in wave form.cpp"
}
namespace sortedTriple {
#include "../Array/EASY/Sorted subsequence of size 3.cpp"
}
namespace stock {
#include "../Array/EASY/Stock buy and sell multiple transaction Allowed.cpp"
}
namespace closestPair {
#include "../Array/EASY/Two Sum Pair Closest to 0.cpp"
}
namespace twoSumExists {
#include "../Array/EASY/Two Sum Pair with given Sum.cpp"
}
namespace unionSorted {
#include "../Array/EASY/Union of Two Sorted Array.cpp"
}
namespace stableBinarySort {
#include "../Array/EASY/stable binary sort.cpp"
}

// Array/Medium
namespace twoSumIndices {
#include "../Array/Medium/2 sum.cpp"
}
namespace rotatedMax {
#include "../Array/Medium/Maximum element in a sorted and rotated array.cpp"
}
namespace rotatedMin {
#include "../Array/Medium/Minimum in a Sorted and Rotated Array.cpp"
}
namespace minSwapsToSort {
#include "../Array/Medium/Minimum swaps to sort an array.cpp"
}
namespace productExcept {
#include "../Array/Medium/Product of Array Except self.cpp"
}
namespace indexEqualsValue {
#include "../Array/Medium/Rearrange an array such that arr[i] = i.cpp"
}
namespace rotationCount {
#include "../Array/Medium/Rotation count in a roated sorted array.cpp"
}
namespace smallestSubarray {
#include "../Array/Medium/Smallest SubArray With sum greater then a given value.cpp"
}
namespace cycleSort {
#include "../Array/Medium/Sort an array which contain 1 to n values.cpp"
}

// Hashing/Easy
namespace countPairsWithSum {
#include "../Hashing/Easy/2 Sum -count pairs wiht given sum.cpp"
}
namespace disjoint {
#include "../Hashing/Easy/Check for Disjoint Array or set.cpp"
}
namespace subsetCheck {
#include "../Hashing/Easy/Check if an array is subset of another array.cpp"
}
namespace equalArrays {
#include "../Hashing/Easy/Check if two arrays are equal or not.cpp"
}
namespace pairDifference {
#include "../Hashing/Easy/Count pair with absolute difference equal to k.cpp"
}
namespace missingInRange {
#include "../Hashing/Easy/Find Missing elements of a range.cpp"
}
namespace minSubsets {
#include "../Hashing/Easy/Minimum subsets with distinct elements.cpp"
}
namespace mostFrequent {
#include "../Hashing/Easy/Most Frequent element in an array.cpp"
}
namespace removeCommon {
#include "../Hashing/Easy/Remove minimum elemnts such that no common elements exist in two arrays.cpp"
}
namespace unionHash {
#include "../Hashing/Easy/Union of Two Array.cpp"
}
namespace missingCount {
#include "../Hashing/Easy/missing elements of a range in an array.cpp"
}

#pragma GCC diagnostic pop
#undef main

typedef std::vector<int> V;

static int checks = 0;
static int failures = 0;

#define CHECK(cond)                                                          \
    do {                                                                     \
        checks++;                                                            \
        if (!(cond)) {                                                       \
            failures++;                                                      \
            std::cerr << "FAIL line " << __LINE__ << ": " << #cond << "\n"; \
        }                                                                    \
    } while (0)

static V sorted(V v) {
    std::sort(v.begin(), v.end());
    return v;
}

// ------------------------------------------------- files fixed in this repo

// two definitions of pushZerosToEnd used to collide; both variants must agree
static void testMoveZeros() {
    V a = {1, 2, 0, 4, 3, 0, 5, 0}, b = a;
    moveZeros::pushZerosToEnd(a);
    moveZeros::pushZerosToEndStablePartition(b);
    CHECK(a == (V{1, 2, 4, 3, 5, 0, 0, 0}));
    CHECK(b == a);

    V noZeros = {10, 20, 30}, onlyZeros = {0, 0}, empty;
    moveZeros::pushZerosToEnd(noZeros);
    moveZeros::pushZerosToEndStablePartition(onlyZeros);
    moveZeros::pushZerosToEnd(empty);
    CHECK(noZeros == (V{10, 20, 30}));
    CHECK(onlyZeros == (V{0, 0}));
    CHECK(empty.empty());
}

// six approaches to the same problem, formerly six functions with one name
static void testOnlyRepeatingAllApproaches() {
    typedef int (*Approach)(V &);
    Approach approaches[] = {
        onlyRepeating::findDuplicateApproach1, onlyRepeating::findDuplicateApproach2,
        onlyRepeating::findDuplicateApproach3, onlyRepeating::findDuplicateApproach4,
        onlyRepeating::findDuplicateApproach5, onlyRepeating::findDuplicateApproach6};

    for (Approach findDuplicate : approaches) {
        // each approach gets its own copy: approach 5 marks the array while it works
        V a = {1, 3, 2, 3, 4}, b = {1, 5, 1, 2, 3, 4}, c = {1, 1};
        CHECK(findDuplicate(a) == 3);
        CHECK(findDuplicate(b) == 1);
        CHECK(findDuplicate(c) == 1);
    }
}

// this file had no #include at all
static void testMissingAndRepeating() {
    V a = {3, 1, 3}, b = {4, 3, 6, 2, 1, 1};
    CHECK(missingRepeating::findTwoElementApproach1(a) == (V{3, 2}));
    CHECK(missingRepeating::findTwoElementApproach2(a) == (V{3, 2}));
    CHECK(missingRepeating::findTwoElementApproach1(b) == (V{1, 5}));
    CHECK(missingRepeating::findTwoElementApproach2(b) == (V{1, 5}));
}

static void testMinSwaps() {
    V oneSwap = {2, 8, 5, 4}, twoSwaps = {10, 19, 6, 3, 5}, alreadySorted = {1, 3, 4, 5, 6};
    V a = oneSwap, b = twoSwaps, c = alreadySorted;
    CHECK(minSwapsToSort::minSwapsApproach1(a) == 1);
    CHECK(minSwapsToSort::minSwapsApproach1(b) == 2);
    CHECK(minSwapsToSort::minSwapsApproach1(c) == 0);
    CHECK(minSwapsToSort::minSwapsApproach2(oneSwap) == 1);
    CHECK(minSwapsToSort::minSwapsApproach2(twoSwaps) == 2);
    CHECK(minSwapsToSort::minSwapsApproach2(alreadySorted) == 0);
}

static void testSmallestSubarray() {
    V a = {1, 4, 45, 6, 0, 19}, b = {1, 10, 5, 2, 7};
    CHECK(smallestSubarray::smallestSubWithSumApproach1(51, a) == 3);
    CHECK(smallestSubarray::smallestSubWithSumApproach2(51, a) == 3);
    CHECK(smallestSubarray::smallestSubWithSumApproach1(9, b) == 1);
    CHECK(smallestSubarray::smallestSubWithSumApproach2(9, b) == 1);

    // no subarray is large enough
    CHECK(smallestSubarray::smallestSubWithSumApproach1(100, b) == 0);
    CHECK(smallestSubarray::smallestSubWithSumApproach2(100, b) == 0);

    // a prefix sum equal to the target is not enough, the next one is:
    // the prefix-sum approach used to return 0 for these
    V c = {5, 3, 0}, d = {1, 1};
    CHECK(smallestSubarray::smallestSubWithSumApproach1(5, c) == 2);
    CHECK(smallestSubarray::smallestSubWithSumApproach2(5, c) == 2);
    CHECK(smallestSubarray::smallestSubWithSumApproach1(1, d) == 2);
    CHECK(smallestSubarray::smallestSubWithSumApproach2(1, d) == 2);
}

// INT_MIN was used without <climits>
static void testMinimumSubsets() {
    minSubsets::minimumSubsets solver;
    CHECK(solver.minimumSubsetWithDistinctElements(V{1, 2, 3, 4}) == 1);
    CHECK(solver.minimumSubsetWithDistinctElements(V{1, 2, 3, 3}) == 2);
    CHECK(solver.minimumSubsetWithDistinctElements(V{5, 5, 5, 5}) == 4);
}

// max_element / min_element were used without <algorithm>
static void testMissingElementsOfRange() {
    missingCount::MissingElements counter;
    CHECK(counter.findMissingElementsRange(V{10, 12, 11, 15}, 10, 15) == 2);
    CHECK(counter.findMissingElementsRange(V{3, 4, 5}, 3, 5) == 0);

    missingInRange::MissingElements finder;
    CHECK(finder.findMissingElements(V{10, 12, 11, 15}, 10, 15) == (V{13, 14}));
    CHECK(finder.findMissingElements(V{1, 14, 11, 51, 15}, 50, 55) == (V{50, 52, 53, 54, 55}));
}

// ----------------------------------------------------- Array/Basic Array DS

static void testBasicArray() {
    V arr = {10, 20, 30, 40, 50}, mixed = {-5, 1, 4, 2, 12};
    CHECK(alternate::alternateElements(arr) == (V{10, 30, 50}));
    CHECK(alternate::alternateElements(mixed) == (V{-5, 4, 12}));
    // the recursive variant collects the same elements (it returns them last to first)
    CHECK(sorted(alternate::alternateElementsRec(arr, 0)) == (V{10, 30, 50}));

    V heights = {16, 17, 4, 3, 5, 2}, rising = {1, 2, 3, 4, 5, 2}, one = {7};
    CHECK(leadersInArray::leaders(heights) == (V{17, 5, 2}));
    CHECK(leadersInArray::leaders(rising) == (V{5, 2}));
    CHECK(leadersInArray::leaders(one) == (V{7}));

    V odd = {1, 3, 5}, even = {2, 4, 6}, empty, twos = {1, 2, 2}, more = {2, 3};
    CHECK(mergeSorted::mearge(odd, even) == (V{1, 2, 3, 4, 5, 6}));
    CHECK(mergeSorted::mearge(empty, even) == even);
    CHECK(mergeSorted::mearge(twos, more) == (V{1, 2, 2, 2, 3}));

    V withDuplicates = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int newSize = removeDup::removeDuplicates(withDuplicates);
    CHECK(newSize == 5);
    CHECK(V(withDuplicates.begin(), withDuplicates.begin() + newSize) == (V{1, 2, 3, 4, 5}));

    V possible = {21, 33, 9, 45, 63}, alsoPossible = {4, 7, 19, 16}, equal = {4, 4, 4, 4}, impossible = {4, 2, 6, 8};
    CHECK(minIncrements::minOps(possible, 6) == 24);
    CHECK(minIncrements::minOps(alsoPossible, 3) == 10);
    CHECK(minIncrements::minOps(equal, 3) == 0);
    CHECK(minIncrements::minOps(impossible, 3) == -1);

    V three = {4, 3, 2}, two = {3, 4};
    CHECK(minCost::cost(three) == 4);
    CHECK(minCost::cost(two) == 3);
}

// --------------------------------------------------------------- Array/EASY

static void testMissingNumber() {
    V a = {1, 2, 3, 5}, b = {8, 2, 4, 5, 3, 7, 1}, onlyOne = {1};
    CHECK(missingNumber::missingNumber(a) == 4);
    CHECK(missingNumber::missingNumberXOR(a) == 4);
    CHECK(missingNumber::missingNumber(b) == 6);
    CHECK(missingNumber::missingNumberXOR(b) == 6);
    CHECK(missingNumber::missingNumber(onlyOne) == 2);
    CHECK(missingNumber::missingNumberXOR(onlyOne) == 2);
}

static void testIntersectionAndUnion() {
    V a = {1, 2, 1, 3, 1}, b = {3, 1, 3, 4, 1};
    CHECK(sorted(intersectionUnsorted::CommonValue(a, b)) == (V{1, 3}));

    V sortedA = {3, 5, 10, 10, 10, 15, 15, 20}, sortedB = {5, 10, 10, 15, 30};
    CHECK(intersectionSorted::intersection(sortedA, sortedB) == (V{5, 10, 15}));

    V c = {1, 1, 2, 2, 2, 4}, d = {2, 2, 4, 4}, e = {1, 2, 3}, f = {4, 5};
    CHECK(unionSorted::findUnion(c, d) == (V{1, 2, 4}));
    CHECK(unionSorted::findUnion(e, f) == (V{1, 2, 3, 4, 5}));

    unionHash::solve solver;
    CHECK(sorted(solver.unionOfTwoArray(V{1, 2, 3, 2, 1}, V{3, 2, 2, 3, 3, 2})) == (V{1, 2, 3}));
}

static void testSubarrayProblems() {
    V a = {-2, 6, -3, -10, 0, 2}, b = {-1, -3, -10, 0, 60}, c = {2, 3, -2, 4};
    CHECK(maxProductSubarray::maxProduct(a) == 180);
    CHECK(maxProductSubarray::maxProduct(b) == 60);
    CHECK(maxProductSubarray::maxProduct(c) == 6);

    V repeat = {-1, 10, 20}, negative = {-1, -2, -3};
    CHECK(repeatedConcat::maxSubArraySumRepeated(repeat, 2) == 59);
    CHECK(repeatedConcat::maxSubArraySumRepeated(negative, 3) == -1);

    V balanced = {1, 2, 0, 3}, none = {1, 1, 1, 1}, withNegatives = {-7, 1, 5, 2, -4, 3, 0};
    CHECK(equilibrium::equilibriumPoint(balanced) == 2);
    CHECK(equilibrium::equilibriumPoint(none) == -1);
    CHECK(equilibrium::equilibriumPoint(withNegatives) == 3);

    CHECK(stock::maximumProfit(V{100, 180, 260, 310, 40, 535, 695}) == 865);
    CHECK(stock::maximumProfit(V{4, 2, 2, 2, 4}) == 2);
    CHECK(stock::maximumProfit(V{9, 7, 4, 1}) == 0);
}

static void testRearrangements() {
    // negatives first, order inside both groups kept
    V signs = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    posNeg::rearrange(signs, 0, signs.size() - 1);
    CHECK(signs == (V{-12, -13, -5, -7, -3, -6, 11, 6, 5}));

    V bits = {0, 1, 0, 1, 1, 1}, moreBits = {1, 0, 1, 0, 1, 0, 0};
    segregate01::segregate0and1(bits);
    segregate01::segregate0and1(moreBits);
    CHECK(bits == (V{0, 0, 1, 1, 1, 1}));
    CHECK(moreBits == (V{0, 0, 0, 0, 1, 1, 1}));

    // wave form: arr[0] >= arr[1] <= arr[2] >= arr[3] ...
    int waveArr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(waveArr) / sizeof(waveArr[0]);
    wave::SortInWave(waveArr, n);
    bool isWave = true;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1 && waveArr[i] > waveArr[i - 1]) isWave = false;
        if (i % 2 == 0 && waveArr[i] < waveArr[i - 1]) isWave = false;
    }
    CHECK(isWave);
    CHECK(sorted(V(waveArr, waveArr + n)) == (V{1, 2, 5, 10, 23, 49, 90}));

    // even numbers first, order inside both groups kept
    V numbers = {0, 1, 2, 3, 4}, binary = {1, 0, 1, 1, 0, 0};
    stableBinarySort::partition(numbers);
    stableBinarySort::partition(binary);
    CHECK(numbers == (V{0, 2, 4, 1, 3}));
    CHECK(binary == (V{0, 0, 0, 1, 1, 1}));

    CHECK(sortedTriple::find3Numbers(V{12, 11, 10, 5, 6, 2, 30}) == (V{5, 6, 30}));
    CHECK(sortedTriple::find3Numbers(V{5, 4, 3, 2, 1}).empty());
    CHECK(sortedTriple::find3Numbers(V{1, 2}).empty());
}

static void testChocolateAndDuplicates() {
    V packets = {7, 3, 2, 4, 9, 12, 56}, samePackets = packets;
    CHECK(chocolate::findMinDiff(packets, 3) == 2);
    CHECK(chocolate::findMinDiff(samePackets, 5) == 7);

    V near = {10, 5, 3, 4, 3, 5, 6}, distinct = {1, 2, 3, 4, 5}, far = {1, 2, 3, 1};
    CHECK(dupWithinK::checkDuplicatesWithinK(near, 3));
    CHECK(!dupWithinK::checkDuplicatesWithinK(distinct, 3));
    CHECK(!dupWithinK::checkDuplicatesWithinK(far, 2));
    CHECK(dupWithinK::checkDuplicatesWithinK(far, 3));
}

static void testTwoSumFamily() {
    V a = {0, -1, 2, -3, 1}, b = {1, -2, 1, 0, 5};
    CHECK(twoSumExists::twoSum(a, -2));
    CHECK(!twoSumExists::twoSum(b, 0));

    V c = {-8, 5, 2, -6}, d = {0, -8, -6, 3}, e = {-7, 4, 1, -2};
    CHECK(closestPair::closestToZero(c) == -1);
    CHECK(closestPair::closestToZero(d) == 3); // -3 and 3 are equally close: the larger sum wins
    CHECK(closestPair::closestToZero(e) == -1);

    V f = {10, 20, 30, 20, 10, 30};
    std::vector<V> expected = {{1, 2}, {2, 3}, {1, 5}, {3, 5}};
    CHECK(twoSumIndices::findAllPairs(f, 50) == expected);
    CHECK(twoSumIndices::findAllPairs(f, 7).empty());

    countPairsWithSum::Solution counter;
    CHECK(counter.countPair(V{1, 5, 7, -1, 5}, 6) == 3);
    CHECK(counter.countPair(V{1, 1, 1, 1}, 2) == 6);

    pairDifference::countPairs difference;
    CHECK(difference.getPairsCount(V{1, 4, 1, 4, 5}, 3) == 4);
    CHECK(difference.getPairsCount(V{8, 16, 12, 16, 4, 0}, 4) == 5);
}

// ------------------------------------------------------------- Array/Medium

static void testRotatedArrays() {
    V a = {4, 5, 6, 9, 10, 1, 2}, b = {50, 10, 20, 30, 40}, notRotated = {1, 2, 3}, one = {5};
    CHECK(rotatedMax::findMax(a) == 10);
    CHECK(rotatedMax::findMax(b) == 50);
    CHECK(rotatedMax::findMax(notRotated) == 3);
    CHECK(rotatedMax::findMax(one) == 5);

    V c = {5, 6, 1, 2, 3, 4}, d = {3, 1, 2}, two = {4, 2};
    CHECK(rotatedMin::findMin(c) == 1);
    CHECK(rotatedMin::findMin(d) == 1);
    CHECK(rotatedMin::findMin(two) == 2);
    CHECK(rotatedMin::findMin(notRotated) == 1);

    // here findMin returns the index of the minimum, which is the rotation count
    V e = {15, 18, 2, 3, 6, 12}, g = {7, 9, 11, 12, 5}, h = {7, 9, 11, 12, 15};
    CHECK(rotationCount::findMin(e) == 2);
    CHECK(rotationCount::findMin(g) == 4);
    CHECK(rotationCount::findMin(h) == 0);
}

static void testProductExceptSelf() {
    V noZero = {10, 3, 5, 6, 2}, oneZero = {12, 0}, twoZeros = {0, 4, 0}, negatives = {-1, 2, -3};
    CHECK(productExcept::productExceptSelf(noZero) == (V{180, 600, 360, 300, 900}));
    CHECK(productExcept::productExceptSelf(oneZero) == (V{0, 12}));
    CHECK(productExcept::productExceptSelf(twoZeros) == (V{0, 0, 0}));
    CHECK(productExcept::productExceptSelf(negatives) == (V{-6, 3, -2}));
}

static void testPlacingValuesAtTheirIndex() {
    V oneToN = {3, 2, 5, 6, 1, 4};
    cycleSort::sort(oneToN);
    CHECK(oneToN == (V{1, 2, 3, 4, 5, 6}));

    V withGaps = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    indexEqualsValue::modifyArray(withGaps);
    CHECK(withGaps == (V{-1, 1, 2, 3, 4, -1, 6, -1, -1, 9}));
}

// ------------------------------------------------------------- Hashing/Easy

static void testHashingSetChecks() {
    disjoint::solve disjointSolver;
    CHECK(!disjointSolver.isDisjoint(V{12, 34, 11, 9, 3}, V{2, 1, 3, 5}));
    CHECK(disjointSolver.isDisjoint(V{12, 34, 11, 9, 3}, V{7, 2, 1, 5}));

    V whole = {11, 1, 13, 21, 3, 7}, part = {11, 3, 7, 1}, other = {10, 5, 2, 23, 19}, notPart = {19, 5, 3};
    subsetCheck::Solution subsetSolver;
    CHECK(subsetCheck::isSubset(whole, part));
    CHECK(subsetSolver.isSubset(whole, part));
    CHECK(!subsetCheck::isSubset(other, notPart));
    CHECK(!subsetSolver.isSubset(other, notPart));

    equalArrays::solve equalSolver;
    CHECK(equalSolver.isEqual(V{1, 2, 5, 4, 0}, V{2, 4, 5, 0, 1}));
    CHECK(!equalSolver.isEqual(V{1, 2, 5}, V{1, 2, 2}));
    CHECK(!equalSolver.isEqual(V{1, 2}, V{1, 2, 3}));

    mostFrequent::Solution frequencySolver;
    V clear = {1, 3, 2, 1, 4, 1}, twenty = {10, 20, 10, 20, 30, 20, 20}, tie = {1, 2, 2, 4, 1};
    CHECK(frequencySolver.mostFreqEle(clear) == 1);
    CHECK(frequencySolver.mostFreqEle(twenty) == 20);
    CHECK(frequencySolver.mostFreqEle(tie) == 2); // same frequency: the larger value wins

    removeCommon::removeMinimumCommonElements removeSolver;
    CHECK(removeSolver.removeCommonElements(V{1, 2, 3, 4}, V{2, 3, 4, 5, 8}) == 3);
    CHECK(removeSolver.removeCommonElements(V{4, 2, 4, 4}, V{4, 3}) == 1);
    CHECK(removeSolver.removeCommonElements(V{1, 2, 3, 4}, V{5, 6, 7}) == 0);
}

int main() {
    testMoveZeros();
    testOnlyRepeatingAllApproaches();
    testMissingAndRepeating();
    testMinSwaps();
    testSmallestSubarray();
    testMinimumSubsets();
    testMissingElementsOfRange();
    testBasicArray();
    testMissingNumber();
    testIntersectionAndUnion();
    testSubarrayProblems();
    testRearrangements();
    testChocolateAndDuplicates();
    testTwoSumFamily();
    testRotatedArrays();
    testProductExceptSelf();
    testPlacingValuesAtTheirIndex();
    testHashingSetChecks();

    std::cout << (checks - failures) << "/" << checks << " checks passed\n";
    return failures == 0 ? 0 : 1;
}
