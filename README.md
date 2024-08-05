# Binary Search Tree Implementation for Account Database
<p>This program imports data from the `accounts.dat` file to create a Binary Search Tree (BST). The BST allows for retrieving records from the database by searching for the Account ID and Record Number, then printing out the results. It also checks if a number is in the database and prints the outcome.</p>


### Program Overview
<p>The program performs the following tasks:</p>
<ul>
    <li>Imports data from `accounts.dat`.</li>
    <li>Creates a Binary Search Tree (BST) from the imported data.</li>
    <li>Searches for a record by Account ID and prints the record if found.</li>
    <li>Checks if an Account ID is in the database and prints the corresponding message.</li>
</ul>

### Compile and Run the Program
<p>To compile and run the program, follow these steps in your terminal:</p>
<b>Compile the Program</b>:

<pre><code>g++ -o bst_account_search bst_account_search.cpp</code></pre>
<b>Run the Program</b>:

<pre><code>./bst_account_search</code></pre>

### Usage
<p>1. The program prompts the user to enter an Account ID.</p>
<ul>
    <li>Based on the entered Account ID, it searches the BST for the corresponding record.</li>
</ul>
<p>2. If the record is found:</p>
<ul>
    <li>The program prints the matched Record Number and the corresponding account record from the database.</li>
</ul>
<p>3. If the record is not found:</p>
<ul>
    <li>The program prints that the Account ID is not in the database.</li>
</ul>

### Contributor 
<p>Lawrence Menegus</p>
