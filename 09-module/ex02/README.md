# `Ford-Johnson Algorithm`, aka merge-insertion sort

The Ford-Johnson algorithm is a [comparison sorting algorithm](https://en.wikipedia.org/wiki/Merge-insertion_sort) that combines the merge sort and insertion sort algorithms. At École 42, where recreating this algo is a mandatory step in the curriculum, it got quite the fame for being diabolical. However, from the way I see it, the algorithm is easy to implement, ok to understand, but very very hard to find information about.

So, inspired by the great guide created by [Carol Daniel](https://github.com/caroldaniel/42sp-cursus-cpp/blob/main/cpp_module_09/ex02/README.md), I want to have my take on trying to explain how it works. After all, you can only confidently say you've learned something after you are able to explain it to someone else.

*Note: **[this](https://warwick.ac.uk/fac/sci/dcs/teaching/material-archive/cs341/fj.pdf)** is where the logic is explained officially, I believe, and guided me through some clarifications of what to do, when and in which order. I, of course, may have understood everything wrong, so please, if you see any mistakes, let me know.*

<br>

<p align="center">
  <img src="https://github.com/user-attachments/assets/84cfff6e-6197-451d-9736-23238161ad70" />
</p>

<br>

## So what's the general idea?

You'll use a logic similar to merge sort in the sense that you'll divide you list/array/container into smaller parts to aid in the sorting process. The insertion sort comes in the end, as you'll use this algorithm to place each element on your sorted list. In between these two well known steps comes the "chaos".


### The Jacobsthal Sequence

Do you remember [Fibonacci](https://en.wikipedia.org/wiki/Fibonacci_sequence)? The infinite sequence that starts with 0 and 1 and each following number is created by the sum of the last two? Ye, the Jacobsthal sequence is much like that one. The difference is that each new number is created by the sum of the last one and the one before that multiplied by two.

So, if Fibonacci is `n = x + (x - 1)`, Jacobsthal is `n = x + 2 * (x- 1)`.

### Cool, but [**for why**](https://www.youtube.com/watch?v=ftKq2aQl5Wg)?

After applying the merge sort idea and dividing the unsorted list into two parts, we will use this sequence to know the order in which we will insert the elements from the unsorted half into the sorted half. It is the glue that connects both algorithms. It's the hiphen between "Merge" and "Insertion" in the title! **ദ്ദി（• ˕ •マ.ᐟ**

<br>

<p align="center">
  <img src="https://github.com/user-attachments/assets/016aa199-1e59-43ec-9561-c0eeff996015" />
</p>

<br>

## Let's get to business!

Now that you understand the general idea behind the algorithm, we can talk specifics. As said before, the process can be generally divided into three stages: the merge, the creation of the insertion order and the insertion itself.

*Note: I won't get into input validation, you can sort that out youself. We are starting here with an unsorted list of numbers in a structure that best suits your needs. For my examples, I'll use a vector and positive integers.*

<br>

### Phase 1) Divide to conquer

*The main objective of this part is to have half list with sorted numbers and half list with numbers yet to be sorted.*

<br>
1.1) First, check if the size of our vector is odd or even. If it is odd, take the last element out and keep it somewhere safe.

```cpp
int					odd = -1;
std::vector<int>	input = {3, 1, 4, 11, 8, 5, 9, 2, 6, 10, 12, 7, 13};

if (input.size() % 2) {
	odd = input.back();
	input.pop_back();
}
```
<br>
1.2) Now, create a vector of pairs. It will receive a grouping of our input vector by pairs.

```cpp
//input = [3, 1, 4, 11, 8, 5, 9, 2, 6, 10, 12, 7];
//odd = 13;

std::vector<std::pair<int, int>>	pairs;

for (std::vector<int>::iterator it = input.begin(); it < input.end(); it += 2) {
	pairs.push_back(std::make_pair(*it, *(it + 1)));
}

//pairs = [(3, 1), (4, 11), (8, 5), (9, 2), (6, 10), (12, 7)];
```

<br>
1.3) With the pairs in hand, sort them individually, placing the bigger one first.

```cpp
typedef std::vector<std::pair<int, int>>::iterator pairVectorIter;

for (pairVectorIter it = pairs.begin(); it < pairs.end(); it++) {
	if (it->first < it->second)
		std::swap(it->first, it->second);
}

//pairs = [(3, 1), (11, 4), (8, 5), (9, 2), (10, 6), (12, 7)];
```

<br>
1.4) Now, sort the whole list of pairs by the first element of each pair, in ascending order.

```cpp
std::sort(pairs.begin(), pairs.end());

//pairs = [(3, 1), (8, 5), (9, 2), (10, 6), (11, 4), (12, 7)];
```

<br>
1.5) Finally, create two new vectors, one for the first element of each pair and another for the second element of each pair.

```cpp
std::vector<int>	main;
std::vector<int>	pend;

for (pairVectorIter it = pairs.begin(); it < pairs.end(); it++) {
	main.push_back(it->first);
	pend.push_back(it->second);
}

//main = [3, 8, 9, 10, 11, 12];
//pend = [1, 5, 2, 6, 4, 7];
```

<br>
1.6) At last, if there was an odd number in the beginning, add it to the end of the pend vector.

```cpp
if (odd != -1)
	pend.push_back(odd);
```

Cool, we are 33% done ~~or something like that heh~~!

<br>

### Phase 2) Who daheck was Jacobsthal?

*The main objective of this part is to generate a list of indexes. This list will tell you on which elements to use the insertion sort from pend to main each time.*

<br>
2.1) Create a vector of integers that will store the Jacobsthal sequence up to the size of the pend vector. Remember that the sequence starts with 0 and 1.

```cpp
std::vector<int>	jacobsthal;

jacobsthal.push_back(0);
jacobsthal.push_back(1);

//nextNumber = second to last * 2 + last;
int	nextNumber = *(jacobsthal.rbegin() + 1) * 2 + jacobsthal.back();

while (nextNumber < pend.size()) {
	jacobsthal.push_back(nextNumber);
	nextNumber = *(jacobsthal.rbegin() + 1) * 2 + jacobsthal.back();
}

//delete the duplicated 1 from the sequence, as we only need unique indexes
jacobsthal.erase(jacobsthal.begin() + 1);

//jacobsthal = [0, 1, 3, 5]
```

<br>
2.2) Create a vector of integers that will store our insertion order list. To create this one, we will add one Jacobsthal number, then look back at our list and see if between this jacobsthal number and the last number added to the list there is any other number missing. If there is, we will add the missing numbers in descending order.

<br>
Example:
<br>

```cpp
//insertion = [0, 1, 3, 2, 5, 4]

//next jacobsthal number is 11, so we add it to the vector
//insertion = [0, 1, 3, 2, 5, 4, 11]

//now, we add the numbers missing between 4 and 11 in descending order
//insertion = [0, 1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6]

//repeat this until we are done with every jacobsthal number and
//the insertion order vector has the same size as our pend vector
```

<br>
To the code:
<br>

```cpp
std::vector<int>	insertion;

//put the first jacobsthal number in the insertion vector: 0
insertion.push_back(jacobsthal.front());

//run this loop until the insertion length is reached
while (insertion.size() < pend.size()) {

	//pop the first element of jacobsthal vector, as we've already added it
	jacobsthal.erase(jacobsthal.begin());

	//if there are still elements in the jacobsthal vector
	if (!jacobsthal.empty()) {
		int		last = insertion.back();	//last element added to the insertion vector
		int		jacob = jacobsthal.front();	//current jacobsthal number being evaluated

		//add the jacobsthal number and decrement it to check for the missing ones
		insertion.push_back(jacob--);

		//while we didn't reach the value of the last index added to the insertion
		//and the insertion vector is still smaller than the pend vector
		while (jacob > last && insertion.size() < pend.size()) {
			std::vector<int>::iterator	begin = insertion.begin();
			std::vector<int>::iterator	end = insertion.end();

			//add to insertion, if the current index wasn't added yet
			if (std::find(begin, end, jacob) == end)
				insertion.push_back(jacob);

			//iterates the missing numbers in descending order
			jacob--;
		}
	}
	//now, if there are no more jacobsthal numbers to add and the insertion vector
	//is still smaller than the pend vector, start from the last index (size - 1)
	else {
		int		missing = pend.size() - 1;

		//and add all the missing numbers until the desired size is reached
		while (insertion.size() < pend.size())
			insertion.push_back(missing--);
	}
}

//insertion = [0, 1, 3, 2, 5, 4]
```

<br>

**ヾ(￣0￣ )ノ**

Oof! You made it through the hardest part. Are you still following along? Don't give up, you're almost there!
<br>
~~For 42 cadets: the other container is ctrl+c ctrl+v~~

<br>

### Phase 3) [TAN DAN DAN DAN DAAAN DAAAAAAN!](https://youtu.be/fm0GWzIZDSc?si=WA0vc_Y0HS8-Wfx9&t=33)

*You have now a main list (already sorted), a pend list of numbers waiting their turn and a list of indexes of who goes first. You are... sorta like the secretary that calls the patients to the doctor's office! :D Not rocket science from here on out.*

<br>

3.1) Run a loop through the insertion order vector and use that number as index to the pend list. Use the function [`std::upper_bound`](https://en.cppreference.com/w/cpp/algorithm/upper_bound) to find the position, in the sorted vector, of the first element greater than your current pend value. Use [`std::insert`](https://en.cppreference.com/w/cpp/container/vector/insert) to place the value right before that position.

```cpp
for (std::vector<int>::iterator it = insertion.begin(); it != insertion.end(); it++) {
	int							value;
	std::vector<int>::iterator	position;

	value = pend[*it];
	position = std::upper_bound(main.begin(), main.end(), value);

	main.insert(position, value);
}

//main = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13];
```

<br>

That's it. You now have a sorted list, made with one of the most obscure sorting algorithms the french wanted us to know about. Are you proud of youself? Cause I am! **(ﾉ◕ヮ◕)\*:・ﾟ✧**

<br>

## Why did we do this?

This algo is important because it finds a way to be unique. It makes fewer comparisons in the worst case scenario than the best previously know algorithms, binary insertion sort and merge sort. It has the minimum possible comparisons for lists up to 22 elements and has the fewest comparisons known for lists up to 46 elements.

For 20 years, it kept the podium as the sorting algorithm with the fewest comparisons known for all input lengths. It is something pretty cool and that, indeed, most people should have at least heard about. Kudos to Lester and Selmer ~~and maybe Stanisław and Czen~~ for the achievement and kudos to 42 as well for adding it to the curriculum.


