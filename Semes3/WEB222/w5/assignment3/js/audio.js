// Data for the "HTML Audio" Page

var audio = {
    controls: true, 
    source: [
        {src: "https://scs.senecac.on.ca/~tanvir.alam/shared/fall-2018/web222/Track03.mp3", type: "audio/mpeg"},
        {src: "https://scs.senecac.on.ca/~tanvir.alam/shared/fall-2018/web222/Track03.ogg", type: "audio/ogg"}
    ]
};


{/* <audio controls>
  <source src="horse.ogg" type="audio/ogg">
  <source src="horse.mp3" type="audio/mpeg">
Your browser does not support the audio element.
</audio> */}


window.onload = function()
{
    var musicList=document.querySelector("#music");
    var song="<audio";
    if(audio.controls==true)
    {
        song+=" controls>";
    }else{
        song+=">";
    }
    for(var i=0; i<audio.source.length;i++)
    {
        song+="<source src=\"" + audio.source[i].src + "\" type=\"" + audio.source[i].type + "\">";
    }
    song += "</audio>";

    musicList.innerHTML = song;
}