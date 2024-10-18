pragma solidity ^0.5.0;

contract whistleblower {
    address public owner;
    modifier onlyOwner() {
        if (msg.sender != owner) {
            revert();
        }
        _;
    }
    
    struct Org {
        uint id;
        address addr;
        string name;
        uint8 otype;     // 0=news/journalist || 1=activists/NGO || 2=lawyers
        string url;
    }
    
    struct Case {
        uint id;
        string title;
        string desc;
        address org;
        string proof;
        uint8 validity;     // 0=not defined yet || 1=valid || 2=invalid
    }
    Org[] public orgs;
    Case[] public cases;
    
    constructor() public {
        owner = msg.sender;
    }
    
    function registerOrg(string memory _name, uint8 _type, string memory _url, address _orgAddr) public onlyOwner {
        Org memory o = Org(orgs.length,_orgAddr, _name, _type, _url);
        orgs.push(o);
    }
    
    function addCase(string memory _title, string memory _desc, uint _orgId, string memory _proof) public {
        require(orgs[_orgId].addr != address(0));
        Case memory c = Case(cases.length, _title, _desc, orgs[_orgId].addr, _proof, 0);
        cases.push(c);
    }
    
    function getCaseCount() public view returns(uint _count) {
        return cases.length;
    }
    function getOrgCount() public view returns(uint _count) {
        return orgs.length;
    }
    function verifyProof(uint _caseId, bool _isValid) public {
        require(cases[_caseId].org == msg.sender);
        if(_isValid) {
            cases[_caseId].validity = 1;
        } else {
            cases[_caseId].validity = 2;
        }
    }
}