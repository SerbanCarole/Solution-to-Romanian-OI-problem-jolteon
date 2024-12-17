# Solution-to-Romanian-OI-problem-jolteon
Problem can be found <a href="https://infoarena.ro/problema/jolteon">here</a>.
For non-Romanian speakers, the problem is asking for an array of n elements how many different contiguous parts of the array
have only elements with odd frequency (in that particular part of the array).
I would like to say that this is a very hard problem in my opinion (even tho the code isn't very big), so here are some hints:
<details>
<summary>Hint1</summary>
The tehniques that you should probably be familiar with for solving this problem are
<ol>
  <li><a href="https://codeforces.com/blog/entry/85900">Xor Hash</a></li>
  <li><a href="https://cp-algorithms.com/data_structures/sqrt_decomposition.html">Square root decomposition</a></li>
</ol>
</details>
<details>
<summary>Hint2</summary>
After learning about xor hashing, what can be said about xor hashing such special subarrays. Find a relation between xor hash
  of all elements and xor hash of distinct elements.
</details>
<details>
<summary>Hint3</summary>
How can we figure out the property of the last hint fast for multiple subarrays? Maybe we can use a previously mentioned data structure.
</details>
