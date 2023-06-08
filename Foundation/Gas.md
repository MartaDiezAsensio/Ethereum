
GAS

Gas refers to the unit that measures the amount of computational effort required to execute
specific operations on the Ethereum network.

Since each Ethereum transaction requires computational resources to execute, each transaction
requires a fee. Gas refers to the fee required to execute a trransaction on ethereum, regardless
of transaction success or failure. 

Gas fees are paid in Ethereum's native currency, ether (ETH). Gas prices are denoted in gwei, which itself is a denomination of ETH - each gwei is equal to 0.000000001 ETH (10-9 ETH). For example, instead of saying that your gas costs 0.000000001 ether, you can say your gas costs 1 gwei. The word 'gwei' itself means 'giga-wei', and it is equal to 1,000,000,000 wei. 


BLOCK SIZE

Before the London Upgrade, Ethereum had fixed-sized blocks. In times of high network demand, these blocks operated at full capacity. As a result, users often had to wait for demand to reduce to get included in a block.

The London Upgrade introduced variable-sized blocks to Ethereum. Each block has a target size of 15 million gas, but the size of blocks will increase or decrease in accordance with network demand, up until the block limit of 30 million gas (2x the target block size). The protocol achieves an equilibrium block size of 15 million on average through the process of tâtonnement. This means if the block size is greater than the target block size, the protocol will increase the base fee for the following block. Similarly, the protocol will decrease the base fee if the block size is less than the target block size. The amount by which the base fee is adjusted is proportional to how far the current block size is from the target.


