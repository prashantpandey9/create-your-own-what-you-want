// this is for detecting button which is pressed

var numberOfDrumButtons = document.querySelectorAll(".drum").length; // length of class with .Drum

function setUpListeners() {
    for (var i = 0; i < numberOfDrumButtons; i++) {
        document.querySelectorAll(".drum")[i].addEventListener("click", function() {
            var buttonInnerHtml = this.innerHTML;

            makeSound(buttonInnerHtml);
            buttonAnimation(buttonInnerHtml);
            document.getElementsByTagName('Body')[0].classList.add('shake');
            setTimeout(function() {
                document.getElementsByTagName('Body')[0].classList.remove('shake');
            }, 200);

        });
    }
// if key is presseed then also it will play

    document.addEventListener("keydown", function(event) {
        makeSound(event.key);
        buttonAnimation(event.key);
        document.getElementsByTagName('Body')[0].classList.add('shake');
        setTimeout(function() {
            document.getElementsByTagName('Body')[0].classList.remove('shake');
        }, 200);

    });
}

const promises = [];

const getAudioObj = (name) => {
    const aud = new Audio(`sounds/${name}.mp3`);
    aud.preload = "auto";
    promises.push(
        new Promise((resolve, reject) => {
            aud.onloadeddata = resolve;
            aud.onerror = reject;
        })
    );
    return aud;
}

const sounds = {
    w: getAudioObj("tom1"),
    a: getAudioObj("tom2"),
    s: getAudioObj("tom3"),
    d: getAudioObj("tom4"),
    j: getAudioObj("snare"),
    k: getAudioObj("crash"),
    l: getAudioObj("kick-bass"),
};

function makeSound(key) {
    if (Object.keys(sounds).includes(key)) sounds[key].cloneNode().play();
}

function buttonAnimation(currentkey) {

    var activeButton = document.querySelector("." + currentkey);

    activeButton.classList.add("pressed");

    setTimeout(function() {
        activeButton.classList.remove("pressed");
    }, 100);

}

(async () => {
    const loader = document.getElementById('popup');
    try {
        await Promise.all(promises);
        setUpListeners();
    } catch (e) {
        alert("Unable to load audio files");
    }
    loader.style.display = "none";
})();
