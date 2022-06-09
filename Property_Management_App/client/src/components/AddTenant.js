import { useState } from 'react';
import Axios from 'axios';
import { Input, Button, Container } from '@chakra-ui/react'


function AddTenant() {
    const [name, setName] = useState('');
    const [age, setAge] = useState('');
    const [address, setAddress] = useState('');
    const [rent, setRent] = useState('');
    const [newRent, setNewRent] = useState('')
    const [newName, setNewName] = useState('')
    const [newAddress, setNewAddress] = useState('')
    const [newLeaseLength, setNewLeaseLength] = useState('')
    const [leaseLength, setLeaseLength] = useState('');
    const [startDate, setStartDate] = useState('');
    const [tenantList, setTenantList] = useState([]);
    const [show, setShow] = useState(false)


    const getTenant = () => {
        Axios.get('http://localhost:3001/tenants').then((response) => {
            console.log(response)
            setTenantList(response.data);
            setShow(true)
        });
    }

    const hideTenants = () => {
        setShow(false)
    }

    const deleteTenant = (id) => {
        Axios.delete(`http://localhost:3001/delete/${id}`).then((response) => {
            setTenantList(tenantList.filter((val) => {
                return val.id !== id
            }))
        })
    }

    const addNewTenant = () => {
        console.log(name + age + address + rent + leaseLength + startDate)
        Axios.post('http://localhost:3001/create', {
            name: name,
            age: age,
            address: address,
            rent: rent,
            leaseLength: leaseLength,
            startDate: startDate,
        }).then(() => {
            console.log('Success');
        })
    }

    const updateRent = (id) => {
        Axios.put('http://localhost:3001/updateRent', {
            rent: newRent,
            id: id
        }).then(() => {
            console.log('Success');
        })
    };

    const updateName = (id) => {
        Axios.put('http://localhost:3001/updateName', {
            name: newName,
            id: id
        }).then((response) => {
            setTenantList(tenantList.map((val) => {
                return val.id === id ?
                    {
                        id: val.id,
                        name: val.newName,
                        age: val.age,
                        address: val.address,
                        rent: val.rent,
                        leaseLength: val.lease_length,
                        startDate: val.startDate
                    }
                    : val
            }))
            alert("update");
        });
    };

    const updateAddress = (id) => {
        Axios.put('http://localhost:3001/updateAddress', {
            address: newAddress,
            id: id
        }).then((response) => {
            setTenantList(tenantList.map((val) => {
                return val.id === id ?
                    {
                        id: val.id,
                        name: val.name,
                        age: val.age,
                        address: val.newAddress,
                        rent: val.rent,
                        leaseLength: val.lease_length,
                        startDate: val.startDate
                    }
                    : val
            }))
            alert("update");
        });
    };

    const updateLeaseLength = (id) => {
        Axios.put('http://localhost:3001/updateLease', {
            leaseLength: newLeaseLength,
            id: id
        }).then((response) => {
            alert("update");
        });
    };

    return (
        <div>
            <div className="add-tenant">
                <Container>

                    <form>
                        <label>Add Tenant</label>
                        <Input
                            size="lg"
                            variant="flushed"
                            placeholder="Name"
                            type="text"
                            onChange={(e) => {
                                setName(e.target.value)
                            }} />
                        <Input
                            size="lg"
                            variant="flushed"
                            placeholder="Age"
                            type="number"
                            onChange={(e) => {
                                setAge(e.target.value)
                            }} />
                        <Input
                            size="lg"
                            variant="flushed"
                            placeholder="Address"
                            type="text"
                            onChange={(e) => {
                                setAddress(e.target.value)
                            }} />
                        <Input
                            size="lg"
                            variant="flushed"
                            placeholder="Rent"
                            type="number"
                            onChange={(e) => {
                                setRent(e.target.value)
                            }} />
                        <Input
                            size="lg"
                            variant="flushed"
                            placeholder="Lease Length (months)"
                            type="number"
                            onChange={(e) => {
                                setLeaseLength(e.target.value)
                            }} />
                        <label></label>
                        <Input
                            size="lg"
                            variant="flushed"
                            placeholder="State Date"
                            type="date"
                            onChange={(e) => {
                                setStartDate(e.target.value)
                            }} />
                        <button onClick={addNewTenant}> Add Tenant</button>
                    </form>
                </Container>
            </div>

            <div className="tenantform-break"></div>

            {show ? <Button className='tenants' onClick={() => { hideTenants() }}> Tenants</Button> : <Button className='tenants' onClick={getTenant}>Refresh Tenants</Button>}
            {
                tenantList.map((val, key) => {
                    return <div className="tenant-list">
                        <div>
                            <h2>Name: {val.name}</h2>
                            <h2>Age: {val.age}</h2>
                            <h2>Address: {val.address}</h2>
                            <h2>Rent: {val.rent}</h2>
                            <h2>Lease Length: {val.lease_length}</h2>
                            <h2>Start date: {val.start_date}</h2>
                        </div>
                        <div className='update-form'>
                            <Input size="xs" variant="flushed" type="text" placeholder="Update Name" onChange={(e) => { setNewName(e.target.value) }} />
                            <Button size="sm" onClick={() => { updateName(val.id) }}> Update Name</Button>
                            <Input variant="flushed" type="text" placeholder="Update Address" onChange={(e) => { setNewAddress(e.target.value) }} />
                            <Button size="sm" onClick={() => { updateAddress(val.id) }}> Update Address</Button>
                            <Input variant="flushed" type="text" placeholder="Update Lease Length" onChange={(e) => { setNewLeaseLength(e.target.value) }} />
                            <Button size="sm" onClick={() => { updateLeaseLength(val.id) }}> Update Lease Length</Button>
                            <Input variant="flushed" type="text" placeholder="Update Rent Amount" onChange={(e) => { setNewRent(e.target.value) }} />
                            <Button size="sm" onClick={() => { updateRent(val.id) }}> Update Rent</Button>
                            <text></text>
                            <Button size="sm" onClick={() => { deleteTenant(val.id) }} > Delete </Button>
                        </div>
                        <br></br>
                    </div>

                })
            }
        </div >
    );
}

export default AddTenant;
