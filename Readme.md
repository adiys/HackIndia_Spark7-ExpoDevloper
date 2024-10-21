# WhistleBlower DApp

WhistleBlower is a decentralized application (DApp) that allows whistleblowers to anonymously report unethical activities within governments or powerful organizations using blockchain technology. The evidence and details submitted are stored immutably on the blockchain and decentralized storage (IPFS), ensuring transparency and preventing censorship.

## Problem Statement

Whistleblowers play a critical role in exposing corruption and unethical practices. However, they often face significant risks like censorship, persecution, or retaliation. A famous example is Dr. Li Wenliang from China, who first identified the coronavirus but was silenced by the authorities. This highlights the need for a secure and anonymous platform where whistleblowers can report unethical practices safely.

## Solution Overview

The WhistleBlower DApp leverages the power of Ethereum and the Matic Network to provide a secure, anonymous platform where users can submit evidence without fear of censorship. Key features include:

- **Anonymity:** Whistleblowers can submit evidence using only an Ethereum address. No prior transaction history is required, ensuring total anonymity.
- **Immutable Evidence:** Once submitted, the evidence is stored on the blockchain, making it tamper-proof and censorship-resistant.
- **Decentralized Storage:** Evidence is stored on the IPFS network, ensuring no central point of failure.
- **Trusted Verification:** Evidence is verified by trusted journalists, NGOs, and lawyers to prevent false claims.
- **Global Visibility:** After verification, evidence becomes visible to the entire world on the public Ethereum blockchain.

## Features

- **Anonymous Submission:** Whistleblowers submit details and evidence without revealing their identity.
- **Censorship Resistance:** Immutable blockchain technology ensures that no government or authority can tamper with the evidence.
- **Decentralized Storage:** Evidence is stored on IPFS to ensure it remains accessible, even if the DApp is taken down.
- **Verification Process:** A trusted group of journalists, NGOs, and legal experts review and verify the authenticity of the submissions.

## Technology Stack

- **Ethereum Blockchain:** For decentralized and transparent evidence submission and verification.
- **Matic Network:** To provide low-cost transactions and ensure scalability without needing ETH.
- **IPFS (InterPlanetary File System):** For decentralized file storage, ensuring data remains available even if the central server goes down.
- **Solidity:** For writing the Smart Contracts that power the DApp.
- **Web3.js:** To interact with the Ethereum blockchain.
- **React.js:** Frontend framework for building the user interface.

## Getting Started

### Prerequisites

- [Node.js](https://nodejs.org/)
- [Truffle](https://www.trufflesuite.com/)
- [Ganache](https://www.trufflesuite.com/ganache) (for local blockchain development)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/whistleblower-dapp.git
   cd whistleblower-dapp
