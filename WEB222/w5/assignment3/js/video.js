// Data for the "HTML Video" Page

var video = {
    controls: true, 
    width: 320,
    height: 240,
    source: [
        {src: "https://scs.senecac.on.ca/~tanvir.alam/shared/fall-2018/web222/movie.mp4", type: "video/mp4"},
        {src: "https://scs.senecac.on.ca/~tanvir.alam/shared/fall-2018/web222/movie.ogg", type: "video/ogg"}
    ]
};

{/* <video width="320" height="240" controls>
  <source src="movie.mp4" type="video/mp4">
  <source src="movie.ogg" type="video/ogg">
  Your browser does not support the video tag.
</video> */}

window.onload = function()
{
    var folder=document.querySelector("#video");
    var vid="<video width=\""+video.width +"\" height=\"" + video.height +"\" ";
    if(video.controls==true)
    {
        vid+="controls>";
    }
    else{
        vid+=">";
    }
    for(var i=0; i<video.source.length;i++)
    {
        vid+="<source src=\"" + video.source[i].src + "\" type=\"" + video.source[i].type + "\">";
    }
    vid+="</video>";

    folder.innerHTML = vid;
}