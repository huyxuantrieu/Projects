import emailjs from 'emailjs-com'
import React from 'react'
import { Input } from '@chakra-ui/react'
import { Container } from '@chakra-ui/react'
import { Textarea } from '@chakra-ui/react'


function ContactForm() {

    function sendEmail(e) {
        e.preventDefault();
        emailjs.sendForm('gmail_service_id', 'template_h7isyfx', e.target, 'Zh11uz2EY8HNAGW4w')
            .then((result) => {
                console.log(result.text);
                alert("Email Sent!")
            }, (error) => {
                console.log(error.text);
                alert("Not Sent")
            });
        e.target.reset()
    }

    function sendEmailTenant(e) {
        e.preventDefault();
        emailjs.sendForm('gmail_service_id', 'template_bvb122w', e.target, 'Zh11uz2EY8HNAGW4w')
            .then((result) => {
                console.log(result.text);
                alert("Email Sent!")

            }, (error) => {
                console.log(error.text);
                alert("Not Sent")
            });
        e.target.reset()

    }

    return (
        <div className="background">

            <div className="contact-forms">
                <div className="first-form">
                    <Container>

                        <form className="form-field" onSubmit={sendEmail}>
                            <h1>Contact Form</h1>
                            <br></br>
                            <Input size="lg" variant="flushed" type="text" placeholder="Landlord Name" name="name" />
                            <br></br>
                            <Input size="lg" variant="flushed" type="text" placeholder="Email Address" name="email" />
                            <Input size="lg" variant="flushed" type="text" placeholder="Subject" name="subject" />
                            <Input size="lg" variant="flushed" type="text" placeholder="Home Address" name="address" />
                            <Input size="lg" variant="flushed" type="text" placeholder="Rent Amount" name="rent" />
                            <Textarea size="lg" variant="flushed" placeholder="Type a message here" name="message" />
                            {/* <button onClick={sendEmail}> Send Message bt</button> */}
                            <Input w="55" size="md" variant="filled" type="submit" value="Send Message" />
                        </form>
                    </Container>

                </div>
                <div className="second-form">
                    <Container>
                        <form className="form-field" onSubmit={sendEmailTenant}>
                            <h1>Reminder Form To Tenants</h1>
                            <br></br>
                            <Input size="lg" variant="flushed" type="text" placeholder="Tenant Name" name="name" />
                            <Input size="lg" variant="flushed" type="email" placeholder="Email Address" name="email" />
                            <Input size="lg" variant="flushed" type="text" placeholder="Subject" name="subject" />
                            <Input size="lg" variant="flushed" type="text" placeholder="Home Address" name="address" />
                            <Input size="lg" variant="flushed" type="text" placeholder="Rent Amount" name="rent" />
                            <Textarea size="lg" variant="flushed" placeholder="Type a message here" name="message" />                            {/* <Button onClick={sendEmailTenant}> Send Message bt</Button> */}
                            <Input w="55" size="md" variant="filled" type="submit" value="Send Message" />
                        </form>
                    </Container>
                    <div className="contactform-break"></div>
                </div>

            </div>
        </div>
    );
}

export default ContactForm