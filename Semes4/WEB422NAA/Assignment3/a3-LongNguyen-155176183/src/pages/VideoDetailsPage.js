// import css
import "./css/VideoDetailsPage.css"
import NavMenu from "../components/NavMenu"
import {useParams} from "react-router-dom";
import {useState,useEffect} from "react";


// import icons
import { GoThumbsdown, GoThumbsup } from "react-icons/go";

function VideoDetailsPage(props) {
    
    let {id}=useParams();
    const [videoFromAPI, setVideoFromApi]=useState({});
    const [like, setLikes]=useState(0);
    const [dislike, setDislikes]=useState(0);
    const [isActiveLike, setActiveLike]=useState(null);
    const [isActiveDislike, setActiveDislike]=useState(null);
    const {addToPlaylist} = props

    useEffect(()=>{
        fetch("http://localhost:3000/videos/"+id).then((response)=>{
            return response.json();
        }).then((jsonData)=>{
            console.log(jsonData);
            setVideoFromApi(jsonData);
            setLikes(jsonData.likes);
            setDislikes(jsonData.dislikes);
        }).catch((error)=>{
            console.error(error);
        })
    },[]);

    let linkYoutube="https://www.youtube.com/embed/"+videoFromAPI.id;
    let profilePic="/"+videoFromAPI.profile_photo;

    const likePressed = () =>{
        if(!isActiveLike){
            console.log("Like Pressed");
            setActiveLike(true);
            setLikes(like+1);
            if(isActiveDislike){
                setActiveDislike(false);
                setDislikes(dislike-1);
            }
        }else{
            console.log("Like Pressed");
            setActiveLike(false);
            setLikes(like-1);
        }
    }

    const DislikePressed = () => {
        if(!isActiveDislike){
            console.log("Dislike Pressed");
            setActiveDislike(true);
            setDislikes(dislike+1);
            if(isActiveLike){
                setActiveLike(false);
                setLikes(like-1);
            }
        }else{
            console.log("Dislike Pressed");
            setActiveDislike(false);
            setDislikes(dislike-1);
        }
    }

    const addToPlaylistPressed = () => {
        console.log(`User want to add ${videoFromAPI.title} to playlist`);
        alert("Saved!");
        addToPlaylist(videoFromAPI)
    }

    return(
        <div>         
            <NavMenu/>
            <section className="video-player-container">
                <iframe width="800" height="450" src={linkYoutube} title="YouTube video player" frameBorder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowFullScreen></iframe>
                <p className="title">{videoFromAPI.title}</p>
                <div className="stats">
                    <p>
                        <span>{videoFromAPI.views}</span>
                        &nbsp;&bull;&nbsp;
                        <span>{videoFromAPI.date_posted}</span>
                    </p>
                    <ul className="links">
                        <li class={isActiveLike ? "pressed" : null} onClick={likePressed}>
                            <GoThumbsup/>
                            &nbsp;&nbsp;
                            <span>{like}</span>
                        </li>
                        <li class={isActiveDislike ? "pressed" : null} onClick={DislikePressed}>
                            <GoThumbsdown/>
                            &nbsp;&nbsp;                            
                            <span>{dislike}</span>
                        </li>
                    </ul>
                </div>
                <div className="video-details">
                    <div>
                        <p className="creator">
                            <img src={profilePic}  className="creator-profile-photo"/>
                            <span>{videoFromAPI.author}</span>                    
                        </p>   
                        <p className="desc">{videoFromAPI.description}</p>
                    </div>
                    <div className="col-right">
                        <button className="btn btn-secondary" onClick={addToPlaylistPressed}>                            
                            ADD TO PLAYLIST
                        </button>                
                    </div>
                </div>                        
            </section>
        </div>
    )
}
export default VideoDetailsPage;