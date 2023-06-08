
EVM (Ethereum Virtual Machine)

PREREQUISITES

	- Hash Functions: A hash function is a mathematical function that converts a numerical input
	value into another compressed numerical value. The input to the hash function is of arbitrary
	length but output is always of fixed size. The hash is sometimes refered as the Digest.
		- Properties: 
			- Pre-Image Resistance: It should be difficult to find any input value x that hashes to
			it's hash. 
			- Second pre-Image Resistance: Given an input and it's hash it shoul be difficult to find
			another input that could produce the same hash. 
			- Collision Resistance: (very similar to Second pre-image Resistance).

	- Merkle Tree: They are also known as Binary Hash Trees. It's a data structure used in cryptography
	and computer science. The tree structure is built by recursively hashing pairs of data until a single 
	root hash is obtained.
	This is how it works:
		1. Data is divided into fixed-size blocks.
		2. Each block is hashed individually using a cryptographic hash function.
		3. The hash values are then paired and hashed again, combining them into a higher-level node.
		4. This process continues recursively until a single root hash value is obtained, representing 
		the entire set of data. 
		5. The root hash is typically used as a compact representation of the entire data set. It allows
		for efficient verification and integrity checking. 


FROM LEDGER TO STATE MACHINE

The analogy of a 'distributed ledger' is often used t describe blockchains like Bitcoin, which anable
descentralized currency using fundamental tools o cryptography. 

While Ethereum has it's own native cryptocurrency (Ether) that follows almost exactly the sameintuitive
rules, it also enables a much more powerful function: smart contracts. 
For tis more complex feature, a more sophisticated analogy is required. instead of a disrtibuted ledger Ethereum is a distributed State Machine.
Ethereum's state is a large data structure which holds not only all accounts and balances, but a machine
state, which can execute arbitrary machine code. The specific ruñese of changing state from blok to block
are deined by the EVM.


THE ETHEREUM STATE TRANSITION FUNCTION

The EVM behaves as a mathematical function would. Given an input, it produces a deterministic output. It 
therefore can be described as having a state transition function: Y(S, T) = S'.
	Given a valid state (S) and a new set of valid transactions (T), the ethereum state transition function
	produces a ew valid output state (S')

In the context of Ethereum, the State is an enormous data structure called modified Merkle Patricia Trie,
which keeps all accounts linked by hashes and reductible to a single root hash stored on the blockchain. 


TRANSACTIONS

Transactions are cryptographically signed instructions from accounts. There are two types of transaactions:
those which result in message calls and those which result in contract creation.

	Contract creation results in the creation of a new contract account containing compiled smart contract
	bytecode. Whenever another account makes a message call to that contract, it executes its bytecode.


EVM INSTRUCTIONS

The EVM executes a Stack Machine with a depth of 1024 items. Eachitem is a 256-bit word, which was chosen for the ease of use with 256-bit cryptography.

During execution, the EVM mantains a transient memory (as a word-adress byte array), which does not persist
between transactions.

Contracts, however do contain a Merkle Patricia storage trie (as a work-adressable word array), associated 
with the account in question and part of the global state.

Compiled smart contract bytecode executes as a number of EVM opcodes, which perform standard stack operations like XOR, AND, ADD, SUB, etc. The EVM also implements a number of blockchain-specific stack operations, such as ADDRESS, BALANCE, BLOCKHASH, etc.