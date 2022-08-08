import React from 'react'
import { useState, useEffect } from 'react'
import { Button, ButtonGroup } from '@chakra-ui/react'
import { Input, Container } from '@chakra-ui/react'
import {
    useDisclosure,
    Modal,
    ModalOverlay,
    ModalContent,
    ModalHeader,
    ModalFooter,
    ModalBody,
    ModalCloseButton,
} from '@chakra-ui/react'



function Todo() {
    const [todo, setTodo] = useState([]);
    const [input, setInput] = useState([]);
    const { isOpen, onOpen, onClose } = useDisclosure()
    const handleSubmit = () => {
        setTodo([...todo, input]);
        setInput('')
    }
    return (
        <div className="a">
            <Container>
                <form>
                    <label>TODO List</label>
                    <Input
                        size='lg'
                        className="todo-input"
                        placeholder="Enter things to do here"
                        variant="flushed"
                        type="text"
                        value={input} onChange={(e) => setInput(e.target.value)} />
                    <br></br>
                    <br></br>
                    <Button className="todo-btn" onClick={handleSubmit}> Save</Button>
                    <br></br>
                    <Button onClick={onOpen}>View Your List</Button>

                    <Modal isOpen={isOpen} onClose={onClose}>
                        <ModalOverlay />
                        <ModalContent>
                            <ModalHeader>Your Todo List Here:</ModalHeader>
                            <ModalCloseButton />
                            <ModalBody>
                                {todo.map((item, index) => (
                                    <p key={index} >
                                        {index + 1}. {item}
                                    </p>
                                ))}
                            </ModalBody>

                            <ModalFooter>
                                <Button colorScheme='blue' mr={3} onClick={onClose}>
                                    Close
                                </Button>
                                {/* <Button variant='ghost'>Secondary Action</Button> */}
                            </ModalFooter>
                        </ModalContent>
                    </Modal>
                </form>
            </Container>
            <div className="todo-break"></div>
        </div>
    )
}

export default Todo;