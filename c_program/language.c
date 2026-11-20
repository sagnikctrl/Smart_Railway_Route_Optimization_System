
#include <string.h>

const char* getTranslation(int choice, const char* key) {
    switch (choice) {

        case 1: // English
            if (strcmp(key, "title") == 0) return "Smart Railway Route Optimization System";
            if (strcmp(key, "subtitle") == 0) return "Route planning using BFS and Dijkstra algorithms";
            if (strcmp(key, "eyebrow") == 0) return "RAILWAY NETWORK • ROUTE PLANNER";
            if (strcmp(key, "intro") == 0) return "Find the best route between stations";
            if (strcmp(key, "introCopy") == 0) return "Compare the route with the fewest stops against the route with the shortest recorded distance.";
            if (strcmp(key, "journey") == 0) return "Plan your journey";
            if (strcmp(key, "instruction") == 0) return "Select your starting station and destination.";
            if (strcmp(key, "from") == 0) return "From station";
            if (strcmp(key, "to") == 0) return "To station";
            if (strcmp(key, "find") == 0) return "Find route";
            if (strcmp(key, "results") == 0) return "Your route results will appear here";
            if (strcmp(key, "resultsInstruction") == 0) return "Choose two different stations and select Find route.";
            if (strcmp(key, "map") == 0) return "Railway network map";
            if (strcmp(key, "mapDescription") == 0) return "A schematic view of the stations and their connections.";
            if (strcmp(key, "station") == 0) return "Station";
            if (strcmp(key, "selectedRoute") == 0) return "Selected route";
            if (strcmp(key, "mapNote") == 0) return "Note: This is a schematic network map, not a geographically accurate map. Station coordinates in the supplied dataset are unverified.";
            if (strcmp(key, "graph") == 0) return "Show graph data (stations and connections)";
            if (strcmp(key, "footer") == 0) return "Academic project demonstration • BFS and Dijkstra route comparison";
           if (strcmp(key, "bfsTitle") == 0) return "BFS · Fewest stops";
if (strcmp(key, "stopsText") == 0) return "stops between stations";
if (strcmp(key, "unweighted") == 0) return "Unweighted search";
if (strcmp(key, "dijkstraTitle") == 0) return "Dijkstra · Shortest distance";
if (strcmp(key, "distanceText") == 0) return "km total distance";
if (strcmp(key, "distanceBased") == 0) return "Distance-based search";
if (strcmp(key, "distanceNote") == 0) return "Distance values are from the supplied project dataset and are marked unverified.";
           if (strcmp(key, "sameStationError") == 0) return "Please choose two different stations.";
if (strcmp(key, "noRouteError") == 0) return "No route was found between these stations.";
if (strcmp(key, "generalError") == 0) return "Something went wrong. Please try again.";
break;

        case 2: // Hindi
            if (strcmp(key, "title") == 0) return "स्मार्ट रेलवे मार्ग अनुकूलन प्रणाली";
            if (strcmp(key, "subtitle") == 0) return "BFS और Dijkstra एल्गोरिदम का उपयोग करके मार्ग योजना";
            if (strcmp(key, "eyebrow") == 0) return "रेलवे नेटवर्क • मार्ग योजनाकार";
            if (strcmp(key, "intro") == 0) return "स्टेशनों के बीच सबसे अच्छा मार्ग खोजें";
            if (strcmp(key, "introCopy") == 0) return "सबसे कम स्टॉप वाले मार्ग की तुलना सबसे कम दर्ज दूरी वाले मार्ग से करें।";
            if (strcmp(key, "journey") == 0) return "अपनी यात्रा की योजना बनाएं";
            if (strcmp(key, "instruction") == 0) return "अपना प्रारंभिक स्टेशन और गंतव्य चुनें।";
            if (strcmp(key, "from") == 0) return "प्रारंभिक स्टेशन";
            if (strcmp(key, "to") == 0) return "गंतव्य स्टेशन";
            if (strcmp(key, "find") == 0) return "मार्ग खोजें";
            if (strcmp(key, "results") == 0) return "आपके मार्ग के परिणाम यहाँ दिखाई देंगे";
            if (strcmp(key, "resultsInstruction") == 0) return "दो अलग-अलग स्टेशन चुनें और मार्ग खोजें।";
            if (strcmp(key, "map") == 0) return "रेलवे नेटवर्क का नक्शा";
            if (strcmp(key, "mapDescription") == 0) return "स्टेशनों और उनके कनेक्शन का एक योजनाबद्ध दृश्य।";
            if (strcmp(key, "station") == 0) return "स्टेशन";
            if (strcmp(key, "selectedRoute") == 0) return "चुना गया मार्ग";
            if (strcmp(key, "mapNote") == 0) return "नोट: यह एक योजनाबद्ध नेटवर्क नक्शा है, भौगोलिक रूप से सटीक नक्शा नहीं। दिए गए डेटा में स्टेशन निर्देशांक सत्यापित नहीं हैं।";
            if (strcmp(key, "graph") == 0) return "ग्राफ डेटा दिखाएं (स्टेशन और कनेक्शन)";
            if (strcmp(key, "footer") == 0) return "शैक्षणिक परियोजना प्रदर्शन • BFS और Dijkstra मार्ग तुलना";

if (strcmp(key, "bfsTitle") == 0) return "BFS · सबसे कम स्टॉप";
if (strcmp(key, "stopsText") == 0) return "स्टेशनों के बीच स्टॉप";
if (strcmp(key, "unweighted") == 0) return "बिना दूरी भार की खोज";
if (strcmp(key, "dijkstraTitle") == 0) return "Dijkstra · सबसे कम दूरी";
if (strcmp(key, "distanceText") == 0) return "किमी कुल दूरी";
if (strcmp(key, "distanceBased") == 0) return "दूरी आधारित खोज";
if (strcmp(key, "distanceNote") == 0) return "दूरी के मान दिए गए प्रोजेक्ट डेटासेट से लिए गए हैं और सत्यापित नहीं हैं।";
if (strcmp(key, "sameStationError") == 0) return "कृपया दो अलग-अलग स्टेशन चुनें।";
if (strcmp(key, "noRouteError") == 0) return "इन स्टेशनों के बीच कोई मार्ग नहीं मिला।";
if (strcmp(key, "generalError") == 0) return "कुछ गलत हुआ। कृपया पुनः प्रयास करें।";
break;

        case 3: // Bengali
            if (strcmp(key, "title") == 0) return "স্মার্ট রেলওয়ে রুট অপ্টিমাইজেশন সিস্টেম";
            if (strcmp(key, "subtitle") == 0) return "BFS এবং Dijkstra অ্যালগরিদম ব্যবহার করে রুট পরিকল্পনা";
            if (strcmp(key, "eyebrow") == 0) return "রেলওয়ে নেটওয়ার্ক • রুট পরিকল্পনাকারী";
            if (strcmp(key, "intro") == 0) return "স্টেশনগুলির মধ্যে সেরা রুট খুঁজুন";
            if (strcmp(key, "introCopy") == 0) return "সবচেয়ে কম স্টপযুক্ত রুটের সঙ্গে সবচেয়ে কম নথিভুক্ত দূরত্বের রুট তুলনা করুন।";
            if (strcmp(key, "journey") == 0) return "আপনার যাত্রার পরিকল্পনা করুন";
            if (strcmp(key, "instruction") == 0) return "আপনার শুরুর স্টেশন এবং গন্তব্য নির্বাচন করুন।";
            if (strcmp(key, "from") == 0) return "শুরুর স্টেশন";
            if (strcmp(key, "to") == 0) return "গন্তব্য স্টেশন";
            if (strcmp(key, "find") == 0) return "রুট খুঁজুন";
            if (strcmp(key, "results") == 0) return "আপনার রুটের ফলাফল এখানে দেখা যাবে";
            if (strcmp(key, "resultsInstruction") == 0) return "দুটি আলাদা স্টেশন নির্বাচন করুন এবং রুট খুঁজুন।";
            if (strcmp(key, "map") == 0) return "রেলওয়ে নেটওয়ার্ক মানচিত্র";
            if (strcmp(key, "mapDescription") == 0) return "স্টেশন এবং তাদের সংযোগের একটি পরিকল্পিত দৃশ্য।";
            if (strcmp(key, "station") == 0) return "স্টেশন";
            if (strcmp(key, "selectedRoute") == 0) return "নির্বাচিত রুট";
            if (strcmp(key, "mapNote") == 0) return "দ্রষ্টব্য: এটি একটি পরিকল্পিত নেটওয়ার্ক মানচিত্র, ভৌগোলিকভাবে নির্ভুল মানচিত্র নয়। প্রদত্ত ডেটাসেটে স্টেশনের স্থানাঙ্ক যাচাই করা হয়নি।";
            if (strcmp(key, "graph") == 0) return "গ্রাফ ডেটা দেখান (স্টেশন এবং সংযোগ)";
            if (strcmp(key, "footer") == 0) return "একাডেমিক প্রকল্প প্রদর্শনী • BFS এবং Dijkstra রুটের তুলনা";
           if (strcmp(key, "bfsTitle") == 0) return "BFS · সবচেয়ে কম স্টপ";
if (strcmp(key, "stopsText") == 0) return "স্টেশনগুলির মধ্যে স্টপ";
if (strcmp(key, "unweighted") == 0) return "ওজনবিহীন অনুসন্ধান";
if (strcmp(key, "dijkstraTitle") == 0) return "Dijkstra · সবচেয়ে কম দূরত্ব";
if (strcmp(key, "distanceText") == 0) return "কিমি মোট দূরত্ব";
if (strcmp(key, "distanceBased") == 0) return "দূরত্বভিত্তিক অনুসন্ধান";
if (strcmp(key, "distanceNote") == 0) return "দূরত্বের মান প্রদত্ত প্রকল্প ডেটাসেট থেকে নেওয়া হয়েছে এবং যাচাই করা হয়নি।";
          if (strcmp(key, "sameStationError") == 0) return "অনুগ্রহ করে দুটি আলাদা স্টেশন নির্বাচন করুন।";
if (strcmp(key, "noRouteError") == 0) return "এই স্টেশনগুলির মধ্যে কোনো রুট পাওয়া যায়নি।";
if (strcmp(key, "generalError") == 0) return "কিছু সমস্যা হয়েছে। অনুগ্রহ করে আবার চেষ্টা করুন।";
break;
    }

    return "";
}

const char* getStationName(int choice, const char* id) {
    switch (choice) {

       case 1:
    if (strcmp(id, "SDAH") == 0) return "Sealdah";
    if (strcmp(id, "BNXR") == 0) return "Bidhan Nagar Road";
    if (strcmp(id, "DDJ") == 0) return "Dum Dum Junction";
    if (strcmp(id, "BLH") == 0) return "Belgharia";
    if (strcmp(id, "AGP") == 0) return "Agarpara";
    if (strcmp(id, "SEP") == 0) return "Sodpur";
    if (strcmp(id, "KDH") == 0) return "Khardaha";
    if (strcmp(id, "TGH") == 0) return "Titagarh";
    if (strcmp(id, "BP") == 0) return "Barrackpore";
    if (strcmp(id, "PTF") == 0) return "Palta";
    if (strcmp(id, "IP") == 0) return "Ichhapur";
    if (strcmp(id, "SNR") == 0) return "Shyamnagar";
    if (strcmp(id, "JGDL") == 0) return "Jagadal";
    if (strcmp(id, "KNR") == 0) return "Kankinara";
    if (strcmp(id, "NH") == 0) return "Naihati Junction";
    if (strcmp(id, "DDC") == 0) return "Dum Dum Cantonment";
    if (strcmp(id, "DGNR") == 0) return "Durganagar";
    if (strcmp(id, "BBT") == 0) return "Birati";
    if (strcmp(id, "BRPK") == 0) return "Bisharpara Kodaliya";
    if (strcmp(id, "NBE") == 0) return "New Barrackpore";
    if (strcmp(id, "MMG") == 0) return "Madhyamgram";
    if (strcmp(id, "HHR") == 0) return "Hridaypur";
    if (strcmp(id, "BT") == 0) return "Barasat Junction";
    break;

        case 2:
            if (strcmp(id, "SDAH") == 0) return "सियालदह";
            if (strcmp(id, "BNXR") == 0) return "बिधान नगर रोड";
            if (strcmp(id, "DDJ") == 0) return "दम दम जंक्शन";
            if (strcmp(id, "BLH") == 0) return "बेलघरिया";
            if (strcmp(id, "AGP") == 0) return "आगरपाड़ा";
            if (strcmp(id, "SEP") == 0) return "सोडपुर";
            if (strcmp(id, "KDH") == 0) return "खड़दह";
            if (strcmp(id, "TGH") == 0) return "टीटागढ़";
            if (strcmp(id, "BP") == 0) return "बैरकपुर";
            if (strcmp(id, "PTF") == 0) return "पलता";
            if (strcmp(id, "IP") == 0) return "इच्छापुर";
            if (strcmp(id, "SNR") == 0) return "श्यामनगर";
            if (strcmp(id, "JGDL") == 0) return "जगदल";
            if (strcmp(id, "KNR") == 0) return "कांकिनाड़ा";
            if (strcmp(id, "NH") == 0) return "नैहाटी जंक्शन";
            if (strcmp(id, "DDC") == 0) return "दम दम कैंटोनमेंट";
            if (strcmp(id, "DGNR") == 0) return "दुर्गानगर";
            if (strcmp(id, "BBT") == 0) return "बिराटी";
            if (strcmp(id, "BRPK") == 0) return "बिशरपाड़ा कोडालिया";
            if (strcmp(id, "NBE") == 0) return "न्यू बैरकपुर";
            if (strcmp(id, "MMG") == 0) return "मध्यमग्राम";
            if (strcmp(id, "HHR") == 0) return "हृदयपुर";
            if (strcmp(id, "BT") == 0) return "बारासात जंक्शन";
            break;

        case 3:
            if (strcmp(id, "SDAH") == 0) return "শিয়ালদহ";
            if (strcmp(id, "BNXR") == 0) return "বিধাননগর রোড";
            if (strcmp(id, "DDJ") == 0) return "দমদম জংশন";
            if (strcmp(id, "BLH") == 0) return "বেলঘরিয়া";
            if (strcmp(id, "AGP") == 0) return "আগরপাড়া";
            if (strcmp(id, "SEP") == 0) return "সোদপুর";
            if (strcmp(id, "KDH") == 0) return "খড়দহ";
            if (strcmp(id, "TGH") == 0) return "টিটাগড়";
            if (strcmp(id, "BP") == 0) return "ব্যারাকপুর";
            if (strcmp(id, "PTF") == 0) return "পলতা";
            if (strcmp(id, "IP") == 0) return "ইছাপুর";
            if (strcmp(id, "SNR") == 0) return "শ্যামনগর";
            if (strcmp(id, "JGDL") == 0) return "জগদ্দল";
            if (strcmp(id, "KNR") == 0) return "কাঁকিনাড়া";
            if (strcmp(id, "NH") == 0) return "নৈহাটি জংশন";
            if (strcmp(id, "DDC") == 0) return "দমদম ক্যান্টনমেন্ট";
            if (strcmp(id, "DGNR") == 0) return "দুর্গানগর";
            if (strcmp(id, "BBT") == 0) return "বিরাটি";
            if (strcmp(id, "BRPK") == 0) return "বিশরপাড়া কোদালিয়া";
            if (strcmp(id, "NBE") == 0) return "নিউ ব্যারাকপুর";
            if (strcmp(id, "MMG") == 0) return "মধ্যমগ্রাম";
            if (strcmp(id, "HHR") == 0) return "হৃদয়পুর";
            if (strcmp(id, "BT") == 0) return "বারাসাত জংশন";
            break;
    }

    return id;
}
