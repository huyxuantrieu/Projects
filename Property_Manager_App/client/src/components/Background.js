import React from 'react';
import videoBg from '../assets/video_city.mp4'

// const backgroundImage = new URL("../assets/background2.jpg", import.meta.url)

const Background = () => {
    return (
        <div className="main">
            {/* <img src={backgroundImage} /> */}
            <video autoPlay loop muted
                style={{
                    position: "absolute",
                    width: "100%",
                    left: "50%",
                    top: "50%",
                    height: "100%",
                    objectFit: "cover",
                    transform: "translate(-50%, -50%)",
                    zIndex: "-1"

                }}>
                <source src={videoBg} />
            </video>
        </div>
    )
}

export default Background;