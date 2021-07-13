import "./css/VideoListing.css"
import Video from "../components/Video";

import {useState,useEffect} from "react";

function VideoListing() {    
    const [videoFromAPI, setVideoFromApi]=useState([]);

    useEffect(()=>{
        fetch("http://localhost:3000/videos").then((response)=>{
            return response.json();
        }).then((jsonData)=>{
            console.log(jsonData);
            setVideoFromApi(jsonData);
        }).catch((error)=>{
            console.error(error);
        })
    },[])

    return(
        <section className="listing-container">      
        {
                videoFromAPI.map((video)=>{
                    return <Video
                    video_thumbnail = {video.video_thumbnail}
                    id={video.id}
                    title={video.title}
                    date_posted= {video.date_posted}
                    profile_photo= {video.profile_photo}
                    author= {video.author}
                    description= {video.description}
                    />
                })
            }                    
        </section>
    )
}
export default VideoListing;
