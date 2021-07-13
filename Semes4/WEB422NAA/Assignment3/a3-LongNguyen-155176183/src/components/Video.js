import "./css/Video.css"
function Video(props) { 

    let link="/videos/"+props.id;
    return(        
        <div className="video-container">
            <img className="video-thumbnail" src= {props.video_thumbnail}/>
            <div className="video-details">
                <p className="name">
                    <a href={link}>{props.title}</a>
                </p>
                <p className="stats">{props.date_posted}</p>
                <p className="creator">
                    <img src= {props.profile_photo} className="creator-profile-photo"/>                    
                    <span>{props.author}</span>
                </p>                    
                <p className="desc">{props.description}</p>
            </div>                
        </div>
    );
}
export default Video;