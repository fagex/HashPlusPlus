<p align="center">
  <img src="/images/hpp.png">
</p>
<hr>
<h1><i>Purpose</i></h1>
Hash++ is a C++20 header-only library that allows a user to retrieve multiple types of hashes from data, files, and files in nested directories. The original purpose behind this library was to create a header-file only implementation of multiple different hash algorithms. You can find a list of the <i>currently</i> supported hash algorithms below.
<br>
<h1><i>Supported Algorithms</i></h1>
<ul>
  <li>MD5</li>
  <li>MD4</li>
  <li>MD2</li>
  <li>SHA-1</li>
  <li>SHA2-224</li>
  <li>SHA2-256</li>
  <li>SHA2-384</li>
  <li>SHA2-512</li>
  <li>SHA2-512/224</li>
  <li>SHA2-512/256</li>
</ul>

Hash++ also aims to be a suitable alternative to heavier, statically and dynamically-linked libraries such as OpenSSL and Crypto++. I created it keeping in mind the mindset of a programmer who simply wants a header-only file that lets them easily and comfortably <i>"just hash sh*t."</i> Does it really have to be that difficult?

No, it doesn't. 
<br>

<h1><i>Algorithm Speed Comparison</i></h1>
Below you can find speed metrics of each algorithm when generating ten million hashes of 4 repetitions of the upper and lowercase alphabet, plus base 10 digits: 4(a-z+A-Z+0-9)

```
+-------------------------------------------+
| 64-bit test:                              |
|   [MD5]          : 15157  ms | 15.157  s  |
|   [MD4]          : 11643  ms | 11.643  s  |
|   [MD2]          : 343729 ms | 343.729 s  |
|   [SHA1]         : 18339  ms | 18.339  s  |
|   [SHA2-224]     : 23712  ms | 23.712  s  |
|   [SHA2-256]     : 23864  ms | 23.864  s  | 
|   [SHA2-384]     : 18213  ms | 18.213  s  | 
|   [SHA2-512]     : 19245  ms | 19.245  s  |
|   [SHA2-512/224] : 16886  ms | 16.886  s  | 
|   [SHA2-512/256] : 17204  ms | 17.204  s  |
|------------------------------|------------|
| 32-bit test:                 |            |
|   [MD5]          : 17994  ms | 17.994  s  |
|   [MD4]          : 12499  ms | 12.499  s  |
|   [MD2]          : 344451 ms | 344.451 s  |
|   [SHA1]         : 20172  ms | 20.172  s  |
|   [SHA2-224]     : 27496  ms | 27.496  s  |
|   [SHA2-256]     : 28034  ms | 28.034  s  |
|   [SHA2-384]     : 43020  ms | 43.020  s  |
|   [SHA2-512]     : 44141  ms | 44.141  s  |
|   [SHA2-512/224] : 42155  ms | 42.155  s  |
|   [SHA2-512/256] : 42106  ms | 42.106  s  |
+-------------------------------------------+
```

<h1><i>Using Hash++</i></h1>
My original design idea behind Hash++ was for it to be <b>simple</b>. This has remained unchanged.
<br><br>
Below you can find the signatures of the <i>only</i> functions necessary to accomplish retrieving hashes from both single or multiple sets of data, files, and files in nested directories. All functions are located in the <code>hashpp</code> namespace under class <code>get</code> (<code>hashpp::get</code>).
<br><br>
You can find examples of Hash++ in use in the <a href="/examples">/examples</a> directory.
<br>
<h3><code>getHash</code></h3>
Retrieve a single hash from a single piece of data.

```cpp
// function to return a resulting hash from selected ALGORITHM and passed data
constexpr static hashpp::hash getHash(hashpp::ALGORITHMS algorithm, std::string data)
```

<h3><code>getHashes</code></h3>
Retrieve a collection of hashes from multiple pieces of data.

```cpp
// function to return a collection of resulting hashes from selected ALGORITHMS and passed data
static hashpp::hashCollection getHashes(std::vector<std::pair<hashpp::ALGORITHMS, std::vector<std::string>>> algorithmDataPairs)
```

<h3><code>getFileHash</code></h3>
Retrieve a single hash from a single file.

```cpp
// function to return a resulting hash from selected ALGORITHM and passed file
static hashpp::hash getFileHash(hashpp::ALGORITHMS algorithm, std::string path)
```

<h3><code>getFilesHashes</code></h3>
Retrieve a collection of hashes from multiple files or files in nested directories.

```cpp
// function to return a collection of resulting hashes from selected ALGORITHMS and passed files (with recursive directory support)
static hashpp::hashCollection getFilesHashes(std::vector<std::pair<hashpp::ALGORITHMS, std::vector<std::string>>> algorithmPathPairs)
```

<br>
<h1><i>Notes</i></h1>
I designed this library <i>without</i> machine endianness in mind. A lot of common architectures are either little-endian or bi-endian, so, I decided to simply design it following what byte-order is most common. This has only been tested on little-endian architectures.
