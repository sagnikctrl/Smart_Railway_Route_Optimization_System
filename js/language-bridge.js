
let getTranslation;
let getStationName;
let currentLanguageNumber = 1;

createLanguageModule().then((Module) => {
    getTranslation = Module.cwrap(
        "getTranslation",
        "string",
        ["number", "string"]
    );

    getStationName = Module.cwrap(
        "getStationName",
        "string",
        ["number", "string"]
    );

    console.log("C WebAssembly language module loaded!");

    updateStationDropdowns();
});

function updateStationDropdowns() {
    if (!getStationName) return;

    ["startSelect", "endSelect"].forEach(selectId => {
        const select = document.getElementById(selectId);

        if (!select) return;

        Array.from(select.options).forEach(option => {
            option.textContent = getStationName(
                currentLanguageNumber,
                option.value
            );
        });
    });
}

function changeLanguage() {
    if (!getTranslation || !getStationName) {
        alert("Language module is still loading. Please try again.");
        return;
    }

    const choice = {
        en: 1,
        hi: 2,
        bn: 3
    };

    const selectedLanguage =
        document.getElementById("languageSelect").value;

    currentLanguageNumber = choice[selectedLanguage];

    const translations = {
        "site-title": "title",
        "site-subtitle": "subtitle",
        "eyebrow": "eyebrow",
        "intro-heading": "intro",
        "intro-copy": "introCopy",
        "route-heading": "journey",
        "journey-instruction": "instruction",
        "fromLabel": "from",
        "toLabel": "to",
        "findBtn": "find",
        "results-heading": "results",
        "results-instruction": "resultsInstruction",
        "map-heading": "map",
        "map-description": "mapDescription",
        "legend-station": "station",
        "legend-route": "selectedRoute",
        "map-note": "mapNote",
        "graph-summary": "graph",
        "footer-text": "footer"
    };

    for (const [elementId, key] of Object.entries(translations)) {
        const element = document.getElementById(elementId);

        if (element) {
            element.textContent =
                getTranslation(currentLanguageNumber, key);
        }
    }

    updateStationDropdowns();
    if (typeof window.findRoute === "function") {
    window.findRoute();
}
}

window.changeLanguage = changeLanguage;

window.getStationNameFor = function(id) {
    if (!getStationName) return id;

    return getStationName(currentLanguageNumber, id);
};

window.getTranslationFor = function(key) {
    if (!getTranslation) return key;

    return getTranslation(currentLanguageNumber, key);
};