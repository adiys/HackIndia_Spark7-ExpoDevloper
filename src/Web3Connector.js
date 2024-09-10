import { useState, useEffect } from 'react';
import { ethers } from 'ethers';

const contractAddress = 'YOUR_SMART_CONTRACT_ADDRESS'; // Replace with your deployed contract address
const abi = [
    {
        "inputs": [],
        "name": "toggleRelay1",
        "outputs": [],
        "stateMutability": "nonpayable",
        "type": "function"
    },
    {
        "inputs": [],
        "name": "toggleRelay2",
        "outputs": [],
        "stateMutability": "nonpayable",
        "type": "function"
    },
    {
        "inputs": [],
        "name": "relay1State",
        "outputs": [
            {
                "internalType": "bool",
                "name": "",
                "type": "bool"
            }
        ],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [],
        "name": "relay2State",
        "outputs": [
            {
                "internalType": "bool",
                "name": "",
                "type": "bool"
            }
        ],
        "stateMutability": "view",
        "type": "function"
    }
];

function Web3Connector() {
    const [contract, setContract] = useState(null);
    const [relay1, setRelay1] = useState(false);
    const [relay2, setRelay2] = useState(false);

    useEffect(() => {
        connectToContract();
    }, []);

    async function connectToContract() {
        const provider = new ethers.providers.JsonRpcProvider("http://127.0.0.1:8545");  // Hardhat RPC URL
        const signer = provider.getSigner(0); // First account
        const contractInstance = new ethers.Contract(contractAddress, abi, signer);
        setContract(contractInstance);
        setRelay1(await contractInstance.relay1State());
        setRelay2(await contractInstance.relay2State());
    }

    async function toggleRelay1() {
        if (contract) {
            const tx = await contract.toggleRelay1();
            await tx.wait();
            setRelay1(await contract.relay1State());
        }
    }

    async function toggleRelay2() {
        if (contract) {
            const tx = await contract.toggleRelay2();
            await tx.wait();
            setRelay2(await contract.relay2State());
        }
    }

    return (
        <div>
            <h1>Home Automation</h1>
            <div>
                <p>Relay 1: {relay1 ? 'ON' : 'OFF'}</p>
                <button onClick={toggleRelay1}>Toggle Relay 1</button>
            </div>
            <div>
                <p>Relay 2: {relay2 ? 'ON' : 'OFF'}</p>
                <button onClick={toggleRelay2}>Toggle Relay 2</button>
            </div>
        </div>
    );
}

export default Web3Connector;
