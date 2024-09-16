// Install ethers.js using npm: npm install ethers express body-parser
const express = require('express');
const bodyParser = require('body-parser');
const { ethers } = require('ethers');

// Ethereum network and contract details
const provider = new ethers.JsonRpcProvider('http://localhost:8545'); // Replace with your local Hardhat network URL
const contractAddress = 'YOUR_CONTRACT_ADDRESS';
const contractABI = [
  "function toggleRelay1() public",
  "function toggleRelay2() public",
  "event RelayToggled(uint relayNumber, bool newState)"
];
const privateKey = 'YOUR_PRIVATE_KEY';
const wallet = new ethers.Wallet(privateKey, provider);
const contract = new ethers.Contract(contractAddress, contractABI, wallet);

const app = express();
app.use(bodyParser.json());

app.get('/toggleRelay1', async (req, res) => {
  try {
    const tx = await contract.toggleRelay1();
    await tx.wait();
    res.send('Relay 1 toggled');
  } catch (error) {
    res.status(500).send(error.toString());
  }
});

app.get('/toggleRelay2', async (req, res) => {
  try {
    const tx = await contract.toggleRelay2();
    await tx.wait();
    res.send('Relay 2 toggled');
  } catch (error) {
    res.status(500).send(error.toString());
  }
});

app.listen(3000, () => console.log('Server running on port 3000'));
