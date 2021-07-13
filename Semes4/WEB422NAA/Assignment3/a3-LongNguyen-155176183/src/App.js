import './App.css';

// page imports
import VideoDetailsPage from "./pages/VideoDetailsPage"
import VideoListing from "./pages/PlaylistPage"
import HomePage from "./pages/HomePage"
import {useState} from "react";


// imports for react router
import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link
 } from "react-router-dom";

function App() {

  const [selectedVideo, setSelectedVideo] = useState([]);

  const addToPlaylist = (video) => {
      console.log("length: " + selectedVideo.length);
      if(selectedVideo.length === 0){
        console.log("ADDED")
        setSelectedVideo([...selectedVideo, video]);
      }else{
        const exist = selectedVideo.find( x => x.id === video.id);
        if(!exist){
          console.log("Not exist");
          setSelectedVideo([...selectedVideo, ...video]);
        }
      }
      console.log("length: " + selectedVideo.length);

      console.log("Selected")
  }

  return (
    <div>
      <Router>
        <Switch>
          <Route exact path="/">
            <HomePage/>
          </Route>
          <Route exact path="/listing">
            <VideoListing videoListing={selectedVideo}/>
          </Route>
          <Route path="/videos/:id">
            <VideoDetailsPage addToPlaylist={addToPlaylist}/>
          </Route>
        </Switch>
      </Router>
    </div>
  );
}

export default App;
