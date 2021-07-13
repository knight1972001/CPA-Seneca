import './App.css';
import {useState} from "react";
function App() {
  const m = 35;
     return (
        <div>
          {
            (m == 25 === true) ? <p>APPLE</p> : <p>BANANA</p>
          }
        </div>
     );
}

export default App;
