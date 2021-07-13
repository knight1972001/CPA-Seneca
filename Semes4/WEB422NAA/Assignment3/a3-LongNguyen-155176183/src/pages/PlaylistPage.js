import "./css/PlaylistPage.css"
import NavMenu from "../components/NavMenu"
import Video from "../components/Video";


function PlaylistPage(props) {
    const {videoListing} = props;

    return(
        <div className="Playlist">            
        <NavMenu/>
        <div>{videoListing.length === 0 && <div>You don't have any videos in your playlist</div>}</div>
        <section className="listing-container">      
            {
                props.videoListing.map((video)=>{
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
        </div>
    )
}
export default PlaylistPage;