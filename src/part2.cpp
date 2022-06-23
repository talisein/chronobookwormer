#include <ranges>
#include <algorithm>
#include <vector>
#include <array>
#include <string_view>
#include <optional>
#include "part2.h"
#include "utils.h"

namespace
{
    using namespace std::string_view_literals;

    constinit std::array vol_1 = std::to_array<volume_definition>({
{ volume::P2V1, "ncx"sv, "toc.ncx"sv, "application/x-dtbncx+xml"sv, std::nullopt, false },
{ volume::P2V1, "stylesheet.css"sv, "Styles/stylesheet.css"sv, "text/css"sv, std::nullopt, false },
{ volume::FB2, "fb2stylesheet.css"sv, "Styles/stylesheet.css"sv, "text/css"sv, std::nullopt, false },
{ volume::P2V1, "Cover.jpg"sv, "Images/Cover.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Insert1.jpg"sv, "Images/Insert1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Insert2.jpg"sv, "Images/Insert2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Insert3.jpg"sv, "Images/Insert3.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Insert4.jpg"sv, "Images/Insert4.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Insert5.jpg"sv, "Images/Insert5.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Insert6.jpg"sv, "Images/Insert6.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Insert7.jpg"sv, "Images/Insert7.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Insert8.jpg"sv, "Images/Insert8.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Insert9.jpg"sv, "Images/Insert9.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "FrontMatter1.jpg"sv, "Images/FrontMatter1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Characters2.jpg"sv, "Images/Characters2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Characters1.jpg"sv, "Images/Characters1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Bonus1.jpg"sv, "Images/Bonus1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "FrontMatter2.jpg"sv, "Images/FrontMatter2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "Bonus2.jpg"sv, "Images/Bonus2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V1, "jnovelclubCMYK.png"sv, "Images/jnovelclubCMYK.png"sv, "image/png"sv, std::nullopt, false },
{ volume::P2V1, "cover"sv, "Text/cover.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Cover"sv), true },
{ volume::P2V1, "frontmatter1.xhtml"sv, "Text/frontmatter1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Color Illustrations"sv), true },
{ volume::P2V1, "frontmatter2.xhtml"sv, "Text/frontmatter2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "characters1.xhtml"sv, "Text/characters1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Characters"sv), true },
{ volume::P2V1, "characters2.xhtml"sv, "Text/characters2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "toc.xhtml"sv, "Text/toc.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "prologue.xhtml"sv, "Text/prologue.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Prologue"sv), true },
{ volume::P2V1, "chapter01.xhtml"sv, "Text/chapter01.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Attendants and the Fealty Ceremony"sv), true },
{ volume::P2V1, "insert1.xhtml"sv, "Text/insert1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter01_1.xhtml"sv, "Text/chapter01_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter02.xhtml"sv, "Text/chapter02.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("A Shrine Maiden’s Job"sv), true },
{ volume::P2V1, "chapter03.xhtml"sv, "Text/chapter03.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Not Like the Other Blue Robes"sv), true },
{ volume::P2V1, "chapter04.xhtml"sv, "Text/chapter04.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Benno’s Meeting With the High Priest"sv), true },
{ volume::P2V1, "chapter05.xhtml"sv, "Text/chapter05.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Meeting Begins"sv), true },
{ volume::P2V1, "insert2.xhtml"sv, "Text/insert2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter05_1.xhtml"sv, "Text/chapter05_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter06.xhtml"sv, "Text/chapter06.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Buying Secondhand Clothes"sv), true },
{ volume::P2V1, "extra1.xhtml"sv, "Text/extra1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("A Place Still Far From Here"sv), true },
{ volume::P2V1, "chapter07.xhtml"sv, "Text/chapter07.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Animosity of Lutz and Gil"sv), true },
{ volume::P2V1, "insert3.xhtml"sv, "Text/insert3.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter07_1.xhtml"sv, "Text/chapter07_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter08.xhtml"sv, "Text/chapter08.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("What They Deserve"sv), true },
{ volume::P2V1, "chapter09.xhtml"sv, "Text/chapter09.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("First Time Outside"sv), true },
{ volume::P2V1, "chapter10.xhtml"sv, "Text/chapter10.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Training the Chefs"sv), true },
{ volume::P2V1, "insert4.xhtml"sv, "Text/insert4.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter10_1.xhtml"sv, "Text/chapter10_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter11.xhtml"sv, "Text/chapter11.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Delia’s Job"sv), true },
{ volume::P2V1, "chapter12.xhtml"sv, "Text/chapter12.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Reality of the Orphanage"sv), true },
{ volume::P2V1, "chapter13.xhtml"sv, "Text/chapter13.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Discussion With the High Priest and My Resolve"sv), true },
{ volume::P2V1, "chapter14.xhtml"sv, "Text/chapter14.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Secret Talk With the High Priest"sv), true },
{ volume::P2V1, "insert5.xhtml"sv, "Text/insert5.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter14_1.xhtml"sv, "Text/chapter14_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter15.xhtml"sv, "Text/chapter15.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Cleaning Up the Orphanage"sv), true },
{ volume::P2V1, "chapter16.xhtml"sv, "Text/chapter16.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Ideas for New Products"sv), true },
{ volume::P2V1, "insert6.xhtml"sv, "Text/insert6.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter16_1.xhtml"sv, "Text/chapter16_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "extra2.xhtml"sv, "Text/extra2.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("An Attendant’s Self-Awareness"sv), true },
{ volume::P2V1, "chapter17.xhtml"sv, "Text/chapter17.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Diptychs and Cards"sv), true },
{ volume::P2V1, "chapter18.xhtml"sv, "Text/chapter18.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Preparing for the Star Festival"sv), true },
{ volume::P2V1, "chapter19.xhtml"sv, "Text/chapter19.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Star Festival"sv), true },
{ volume::P2V1, "insert7.xhtml"sv, "Text/insert7.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter19_1.xhtml"sv, "Text/chapter19_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter20.xhtml"sv, "Text/chapter20.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("After the Festival"sv), true },
{ volume::P2V1, "chapter21.xhtml"sv, "Text/chapter21.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Lutz’s Path Through Life"sv), true },
{ volume::P2V1, "chapter22.xhtml"sv, "Text/chapter22.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Lutz Running Away from Home"sv), true },
{ volume::P2V1, "insert8.xhtml"sv, "Text/insert8.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter22_1.xhtml"sv, "Text/chapter22_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter23.xhtml"sv, "Text/chapter23.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The High Priest’s Letter of Invitation"sv), true },
{ volume::P2V1, "chapter24.xhtml"sv, "Text/chapter24.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Family Meeting at the Temple"sv), true },
{ volume::P2V1, "insert9.xhtml"sv, "Text/insert9.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "chapter24_1.xhtml"sv, "Text/chapter24_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "epilogue.xhtml"sv, "Text/epilogue.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Epilogue"sv), true },
{ volume::FB2, "side2.xhtml"sv, "Text/side2.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("I’m Not Givin’ Ya My Daughter!"sv), true },
{ volume::P2V1, "afterword.xhtml"sv, "Text/afterword.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Afterword"sv), true },
{ volume::P2V1, "bonus1.xhtml"sv, "Text/bonus1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Bonus High Resolution Illustrations"sv), true },
{ volume::P2V1, "bonus2.xhtml"sv, "Text/bonus2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V1, "signup.xhtml"sv, "Text/signup.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("About J-Novel Club"sv), true },
{ volume::P2V1, "copyright.xhtml"sv, "Text/copyright.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Copyright"sv), true },
        });


constinit std::array vol_2 = std::to_array<volume_definition>({
{ volume::P2V2, "ncx"sv, "toc.ncx"sv, "application/x-dtbncx+xml"sv, std::nullopt, false },
{ volume::P2V2, "stylesheet.css"sv, "Styles/stylesheet.css"sv, "text/css"sv, std::nullopt, false },
{ volume::FB2, "fb2stylesheet.css"sv, "Styles/stylesheet.css"sv, "text/css"sv, std::nullopt, false },
{ volume::P2V2, "Cover.jpg"sv, "Images/Cover.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Insert1.jpg"sv, "Images/Insert1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Insert2.jpg"sv, "Images/Insert2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Insert3.jpg"sv, "Images/Insert3.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Insert4.jpg"sv, "Images/Insert4.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Insert5.jpg"sv, "Images/Insert5.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Insert6.jpg"sv, "Images/Insert6.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Insert7.jpg"sv, "Images/Insert7.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Insert8.jpg"sv, "Images/Insert8.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Insert9.jpg"sv, "Images/Insert9.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "FrontMatter1.jpg"sv, "Images/FrontMatter1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "FrontMatter2.jpg"sv, "Images/FrontMatter2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Bonus1.jpg"sv, "Images/Bonus1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Bonus2.jpg"sv, "Images/Bonus2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Characters1.jpg"sv, "Images/Characters1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "Characters2.jpg"sv, "Images/Characters2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V2, "jnovelclubCMYK.png"sv, "Images/jnovelclubCMYK.png"sv, "image/png"sv, std::nullopt, false },
{ volume::P2V2, "cover"sv, "Text/cover.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Cover"sv), true },
{ volume::P2V2, "frontmatter1.xhtml"sv, "Text/frontmatter1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Color Illustrations"sv), true },
{ volume::P2V2, "frontmatter2.xhtml"sv, "Text/frontmatter2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "characters1.xhtml"sv, "Text/characters1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Characters"sv), true },
{ volume::P2V2, "characters2.xhtml"sv, "Text/characters2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "toc.xhtml"sv, "Text/toc.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "prologue.xhtml"sv, "Text/prologue.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Prologue"sv), true },
{ volume::P2V2, "chapter01.xhtml"sv, "Text/chapter01.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("One Wilma, Please"sv), true },
{ volume::P2V2, "insert1.xhtml"sv, "Text/insert1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter01_1.xhtml"sv, "Text/chapter01_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter02.xhtml"sv, "Text/chapter02.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Rosina and Harspiels"sv), true },
{ volume::P2V2, "chapter03.xhtml"sv, "Text/chapter03.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("An Attendant’s Job"sv), true },
{ volume::P2V2, "extra1.xhtml"sv, "Text/extra1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Attendant of an Apprentice Blue Shrine Maiden"sv), true },
{ volume::P2V2, "insert9.xhtml"sv, "Text/insert9.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "extra1_1.xhtml"sv, "Text/extra1_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter04.xhtml"sv, "Text/chapter04.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Italian Restaurant’s Interior Decoration"sv), true },
{ volume::P2V2, "insert2.xhtml"sv, "Text/insert2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter04_1.xhtml"sv, "Text/chapter04_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter05.xhtml"sv, "Text/chapter05.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("How to Run a Restaurant"sv), true },
{ volume::P2V2, "chapter06.xhtml"sv, "Text/chapter06.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Significance of Going Outside"sv), true },
{ volume::P2V2, "chapter07.xhtml"sv, "Text/chapter07.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Preparing to Make Ink"sv), true },
{ volume::P2V2, "chapter08.xhtml"sv, "Text/chapter08.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Black Oil Paint"sv), true },
{ volume::P2V2, "chapter09.xhtml"sv, "Text/chapter09.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Making Picture Books with Woodblock Printing"sv), true },
{ volume::P2V2, "chapter10.xhtml"sv, "Text/chapter10.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Black-and-White Picture Books"sv), true },
{ volume::P2V2, "chapter11.xhtml"sv, "Text/chapter11.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Preparing for the Children’s Bible"sv), true },
{ volume::P2V2, "insert3.xhtml"sv, "Text/insert3.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter11_1.xhtml"sv, "Text/chapter11_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter12.xhtml"sv, "Text/chapter12.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Binding Children’s Bibles"sv), true },
{ volume::P2V2, "insert4.xhtml"sv, "Text/insert4.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter12_1.xhtml"sv, "Text/chapter12_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter13.xhtml"sv, "Text/chapter13.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Missing the Harvest Festival"sv), true },
{ volume::P2V2, "chapter14.xhtml"sv, "Text/chapter14.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Myne Decimal System"sv), true },
{ volume::FB2, "side3.xhtml"sv, "Text/side3.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("My Handful of a Little Sister"sv), true },
{ volume::P2V2, "chapter15.xhtml"sv, "Text/chapter15.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("A Book for Benno and First Fitting"sv), true },
{ volume::P2V2, "chapter16.xhtml"sv, "Text/chapter16.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Cinderella and a Book for the High Priest"sv), true },
{ volume::P2V2, "chapter17.xhtml"sv, "Text/chapter17.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("A Discussion About Winter Preparations"sv), true },
{ volume::P2V2, "chapter18.xhtml"sv, "Text/chapter18.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Off to Buy Winter Clothes"sv), true },
{ volume::P2V2, "insert5.xhtml"sv, "Text/insert5.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter18_1.xhtml"sv, "Text/chapter18_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::FB2, "side4.xhtml"sv, "Text/side4.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Studying Literature and Picture Books"sv), true },
{ volume::P2V2, "chapter19.xhtml"sv, "Text/chapter19.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Butchering and Absence"sv), true },
{ volume::P2V2, "extra2.xhtml"sv, "Text/extra2.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Apprentice Chef in the Temple"sv), true },
{ volume::P2V2, "chapter20.xhtml"sv, "Text/chapter20.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The End of Winter Preparations"sv), true },
{ volume::P2V2, "chapter21.xhtml"sv, "Text/chapter21.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Summons from the Knight’s Order"sv), true },
{ volume::P2V2, "insert6.xhtml"sv, "Text/insert6.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter21_1.xhtml"sv, "Text/chapter21_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter22.xhtml"sv, "Text/chapter22.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Trombe Extermination"sv), true },
{ volume::P2V2, "chapter23.xhtml"sv, "Text/chapter23.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Rescue and Reprimand"sv), true },
{ volume::P2V2, "chapter24.xhtml"sv, "Text/chapter24.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Healing Ritual"sv), true },
{ volume::P2V2, "insert7.xhtml"sv, "Text/insert7.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "chapter24_1.xhtml"sv, "Text/chapter24_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "epilogue.xhtml"sv, "Text/epilogue.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Epilogue"sv), true },
{ volume::P2V2, "insert8.xhtml"sv, "Text/insert8.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "epilogue_1.xhtml"sv, "Text/epilogue_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "afterword.xhtml"sv, "Text/afterword.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Afterword"sv), true },
{ volume::P2V2, "bonus1.xhtml"sv, "Text/bonus1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Bonus High Resolution Illustrations"sv), true },
{ volume::P2V2, "bonus2.xhtml"sv, "Text/bonus2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V2, "signup.xhtml"sv, "Text/signup.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("About J-Novel Club"sv), true },
{ volume::P2V2, "copyright.xhtml"sv, "Text/copyright.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Copyright"sv), true },
        });


    constinit std::array vol_3 = std::to_array<volume_definition>({
{ volume::P2V3, "ncx"sv, "toc.ncx"sv, "application/x-dtbncx+xml"sv, std::nullopt, false },
{ volume::P2V3, "stylesheet.css"sv, "Styles/stylesheet.css"sv, "text/css"sv, std::nullopt, false },
{ volume::P2V4, "p2v4stylesheet.css"sv, "Styles/stylesheet.css"sv, "text/css"sv, std::nullopt, false },
{ volume::P2V3, "jnovelclubCMYK.png"sv, "Images/jnovelclubCMYK.png"sv, "image/png"sv, std::nullopt, false },
{ volume::P2V3, "Bonus1.jpg"sv, "Images/Bonus1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Bonus2.jpg"sv, "Images/Bonus2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Characters1.jpg"sv, "Images/Characters1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Characters2.jpg"sv, "Images/Characters2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Cover.jpg"sv, "Images/Cover.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "FrontMatter1.jpg"sv, "Images/FrontMatter1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "FrontMatter2.jpg"sv, "Images/FrontMatter2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Insert1.jpg"sv, "Images/Insert1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Insert2.jpg"sv, "Images/Insert2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Insert3.jpg"sv, "Images/Insert3.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Insert4.jpg"sv, "Images/Insert4.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Insert5.jpg"sv, "Images/Insert5.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Insert6.jpg"sv, "Images/Insert6.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Insert7.jpg"sv, "Images/Insert7.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Insert8.jpg"sv, "Images/Insert8.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Insert9.jpg"sv, "Images/Insert9.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "Map.jpg"sv, "Images/Map.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V3, "cover"sv, "Text/cover.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Cover"sv), true },
{ volume::P2V3, "frontmatter1.xhtml"sv, "Text/frontmatter1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Color Illustrations"sv), true },
{ volume::P2V3, "frontmatter2.xhtml"sv, "Text/frontmatter2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "map.xhtml"sv, "Text/map.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Map of Ehrenfest Duchy"sv), true },
{ volume::P2V3, "characters1.xhtml"sv, "Text/characters1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Characters"sv), true },
{ volume::P2V3, "characters2.xhtml"sv, "Text/characters2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "toc.xhtml"sv, "Text/toc.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "prologue.xhtml"sv, "Text/prologue.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Prologue"sv), true },
{ volume::P2V3, "chapter01.xhtml"sv, "Text/chapter01.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Printing Guild"sv), true },
{ volume::P2V3, "chapter02.xhtml"sv, "Text/chapter02.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Johann’s Task"sv), true },
{ volume::P2V3, "insert1.xhtml"sv, "Text/insert1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "chapter02_1.xhtml"sv, "Text/chapter02_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "chapter03.xhtml"sv, "Text/chapter03.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Ink Guild and the Beginning of Winter"sv), true },
{ volume::P2V3, "chapter04.xhtml"sv, "Text/chapter04.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Winter Hibernation and Handiwork"sv), true },
{ volume::P2V3, "chapter05.xhtml"sv, "Text/chapter05.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Meeting of the Minds"sv), true },
{ volume::P2V3, "chapter06.xhtml"sv, "Text/chapter06.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Punishment for the Knight’s Order and My Future"sv), true },
{ volume::P2V3, "insert2.xhtml"sv, "Text/insert2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "chapter06_1.xhtml"sv, "Text/chapter06_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "chapter07.xhtml"sv, "Text/chapter07.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Daily Winter Life"sv), true },
{ volume::P2V3, "chapter08.xhtml"sv, "Text/chapter08.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Dedication Ritual"sv), true },
{ volume::P2V3, "chapter09.xhtml"sv, "Text/chapter09.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Rosina’s Coming of Age Ceremony"sv), true },
{ volume::P2V3, "insert3.xhtml"sv, "Text/insert3.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "chapter10.xhtml"sv, "Text/chapter10.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Rumtopf and Shoes"sv), true },
{ volume::P2V3, "chapter11.xhtml"sv, "Text/chapter11.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Completion of the Metal Letter Types"sv), true },
{ volume::P2V3, "extra2.xhtml"sv, "Text/extra2.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Title of “Gutenberg”"sv), true },
{ volume::P2V3, "insert9.xhtml"sv, "Text/insert9.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "extra2_1.xhtml"sv, "Text/extra2_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "chapter12.xhtml"sv, "Text/chapter12.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Temple Stay Extended"sv), true },
{ volume::P2V3, "insert4.xhtml"sv, "Text/insert4.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "chapter12_1.xhtml"sv, "Text/chapter12_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "extra1.xhtml"sv, "Text/extra1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Lunchtime in the Temple"sv), true },
{ volume::P2V3, "chapter13.xhtml"sv, "Text/chapter13.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Preparing for the Spring Prayer"sv), true },
{ volume::P2V3, "insert5.xhtml"sv, "Text/insert5.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "chapter14.xhtml"sv, "Text/chapter14.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Spring Prayer"sv), true },
{ volume::P2V3, "chapter15.xhtml"sv, "Text/chapter15.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("An After-Meal Invitation"sv), true },
{ volume::P2V3, "chapter16.xhtml"sv, "Text/chapter16.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Ambush"sv), true },
{ volume::P2V3, "insert6.xhtml"sv, "Text/insert6.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "chapter16_1.xhtml"sv, "Text/chapter16_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "chapter17.xhtml"sv, "Text/chapter17.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Wild and Uncontrollable Blue Priest"sv), true },
{ volume::P2V3, "chapter18.xhtml"sv, "Text/chapter18.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Visit to the Orphanage and Workshop"sv), true },
{ volume::P2V3, "insert7.xhtml"sv, "Text/insert7.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "chapter18_1.xhtml"sv, "Text/chapter18_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "extra8.xhtml"sv, "Text/extra8.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Leon—Sylvester Undercover"sv), true },
{ volume::P2V3, "chapter19.xhtml"sv, "Text/chapter19.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Talking with the High Priest and Returning Home"sv), true },
{ volume::P2V3, "chapter20.xhtml"sv, "Text/chapter20.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("A New Member of the Family"sv), true },
{ volume::P2V3, "insert8.xhtml"sv, "Text/insert8.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "chapter20_1.xhtml"sv, "Text/chapter20_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "epilogue.xhtml"sv, "Text/epilogue.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Epilogue"sv), true },
{ volume::P2V3, "afterword.xhtml"sv, "Text/afterword.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Afterword"sv), true },
{ volume::P2V3, "bonus1.xhtml"sv, "Text/bonus1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Bonus High Resolution Illustrations"sv), true },
{ volume::P2V3, "bonus2.xhtml"sv, "Text/bonus2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V3, "signup.xhtml"sv, "Text/signup.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("About J-Novel Club"sv), true },
{ volume::P2V3, "copyright.xhtml"sv, "Text/copyright.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Copyright"sv), true },
        });


constinit std::array vol_4 = std::to_array<volume_definition>({
{ volume::P2V4, "ncx"sv, "toc.ncx"sv, "application/x-dtbncx+xml"sv, std::nullopt, false },
{ volume::P2V4, "stylesheet.css"sv, "Styles/stylesheet.css"sv, "text/css"sv, std::nullopt, false },
{ volume::FB2, "fb2stylesheet.css"sv, "Styles/stylesheet.css"sv, "text/css"sv, std::nullopt, false },
{ volume::FB1, "fb1stylesheet.css"sv, "Styles/stylesheet.css"sv, "text/css"sv, std::nullopt, false },
{ volume::P2V4, "jnovelclubCMYK.png"sv, "Images/jnovelclubCMYK.png"sv, "image/png"sv, std::nullopt, false },
{ volume::P2V4, "Bonus1.jpg"sv, "Images/Bonus1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Bonus2.jpg"sv, "Images/Bonus2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Characters1.jpg"sv, "Images/Characters1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Characters2.jpg"sv, "Images/Characters2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Cover.jpg"sv, "Images/Cover.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "FrontMatter1.jpg"sv, "Images/FrontMatter1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "FrontMatter2.jpg"sv, "Images/FrontMatter2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Insert1.jpg"sv, "Images/Insert1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Insert2.jpg"sv, "Images/Insert2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Insert3.jpg"sv, "Images/Insert3.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Insert4.jpg"sv, "Images/Insert4.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Insert5.jpg"sv, "Images/Insert5.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Insert6.jpg"sv, "Images/Insert6.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Insert7.jpg"sv, "Images/Insert7.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Insert8.jpg"sv, "Images/Insert8.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Insert9.jpg"sv, "Images/Insert9.jpg"sv, "image/jpeg"sv, std::nullopt, false },

{ volume::P2V4, "Manga1.jpg"sv, "Images/Manga1.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Manga2.jpg"sv, "Images/Manga2.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "Map.jpg"sv, "Images/Map.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "cover"sv, "Text/cover.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Cover"sv), true },
{ volume::P2V4, "frontmatter1.xhtml"sv, "Text/frontmatter1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Color Illustrations"sv), true },
{ volume::P2V4, "frontmatter2.xhtml"sv, "Text/frontmatter2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "map.xhtml"sv, "Text/map.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Map of Ehrenfest Duchy"sv), true },
{ volume::P2V4, "characters1.xhtml"sv, "Text/characters1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Characters"sv), true },
{ volume::P2V4, "characters2.xhtml"sv, "Text/characters2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "toc.xhtml"sv, "Text/toc.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "prologue.xhtml"sv, "Text/prologue.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Prologue"sv), true },
{ volume::P2V4, "chapter1.xhtml"sv, "Text/chapter1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Caring for Kamil"sv), true },
{ volume::P2V4, "chapter2.xhtml"sv, "Text/chapter2.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Abandoned Child"sv), true },
{ volume::P2V4, "insert1.xhtml"sv, "Text/insert1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter2_1.xhtml"sv, "Text/chapter2_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter3.xhtml"sv, "Text/chapter3.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("What to Do About Dirk"sv), true },
{ volume::P2V4, "chapter4.xhtml"sv, "Text/chapter4.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Ink Guild and Succession"sv), true },
{ volume::P2V4, "chapter5.xhtml"sv, "Text/chapter5.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Researching Color-Making"sv), true },
{ volume::P2V4, "insert2.xhtml"sv, "Text/insert2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter5_1.xhtml"sv, "Text/chapter5_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter6.xhtml"sv, "Text/chapter6.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Challenging Wax Stencils"sv), true },
{ volume::P2V4, "extra7.xhtml"sv, "Text/extra7.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Josef—Beruf Certification"sv), true },
{ volume::P2V4, "chapter7.xhtml"sv, "Text/chapter7.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Delia’s Progress"sv), true },
{ volume::P2V4, "chapter8.xhtml"sv, "Text/chapter8.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Both Sides of the Story"sv), true },
{ volume::P2V4, "chapter9.xhtml"sv, "Text/chapter9.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Two Who Left"sv), true },
{ volume::P2V4, "chapter10.xhtml"sv, "Text/chapter10.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Shadow Falls"sv), true },
{ volume::P2V4, "insert3.xhtml"sv, "Text/insert3.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter10_1.xhtml"sv, "Text/chapter10_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter11.xhtml"sv, "Text/chapter11.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Noble from Another Duchy"sv), true },
{ volume::P2V4, "insert4.xhtml"sv, "Text/insert4.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter11_1.xhtml"sv, "Text/chapter11_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter12.xhtml"sv, "Text/chapter12.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Black Charm"sv), true },
{ volume::P2V4, "insert5.xhtml"sv, "Text/insert5.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter12_1.xhtml"sv, "Text/chapter12_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter13.xhtml"sv, "Text/chapter13.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The Source of Strife"sv), true },
{ volume::P2V4, "insert6.xhtml"sv, "Text/insert6.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter13_1.xhtml"sv, "Text/chapter13_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter14.xhtml"sv, "Text/chapter14.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("The New Me"sv), true },
{ volume::P2V4, "chapter15.xhtml"sv, "Text/chapter15.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Ripped Apart"sv), true },
{ volume::P2V4, "insert7.xhtml"sv, "Text/insert7.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "chapter15_1.xhtml"sv, "Text/chapter15_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "extra2.xhtml"sv, "Text/extra2.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Sylvester—Cleaning up the Mess"sv), true },
{ volume::P2V4, "extra1.xhtml"sv, "Text/extra1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Freida—A Visit to the Noble’s Quarter"sv), true },
{ volume::P2V4, "extra3.xhtml"sv, "Text/extra3.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Arno—Fran and I"sv), true },
{ volume::P2V4, "extra4.xhtml"sv, "Text/extra4.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Benno—Maybe Lessen the Workload"sv), true },
{ volume::FB1, "temple.xhtml"sv, "Text/temple.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Temple Tour by Miya Kazuki"sv), true },
{ volume::FB1, "x24.xhtml"sv, "Text/24.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::FB1, "temple_1.xhtml"sv, "Text/temple_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::FB1, "x24.jpg"sv, "Images/24.jpg"sv, "image/jpeg"sv, std::nullopt, false },
{ volume::P2V4, "epilogue.xhtml"sv, "Text/epilogue.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Epilogue"sv), true },
{ volume::P2V4, "insert8.xhtml"sv, "Text/insert8.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "epilogue_1.xhtml"sv, "Text/epilogue_1.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "extra5.xhtml"sv, "Text/extra5.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Fran—To Serve as the High Bishop’s Attendant"sv), true },
{ volume::P2V4, "extra6.xhtml"sv, "Text/extra6.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Effa—Facing the Future"sv), true },
{ volume::P2V4, "insert9.xhtml"sv, "Text/insert9.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "afterword.xhtml"sv, "Text/afterword.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Afterword"sv), true },
{ volume::P2V4, "manga1.xhtml"sv, "Text/manga1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Coming Out of Nowhere to Celebrate the Conclusion of Part 2, It’s the First Ever End of Volume Bonuses! by You Shiina"sv), true },
{ volume::P2V4, "manga2.xhtml"sv, "Text/manga2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "bonus1.xhtml"sv, "Text/bonus1.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Bonus High Resolution Illustrations"sv), true },
{ volume::P2V4, "bonus2.xhtml"sv, "Text/bonus2.xhtml"sv, "application/xhtml+xml"sv, std::nullopt, true },
{ volume::P2V4, "signup.xhtml"sv, "Text/signup.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("About J-Novel Club"sv), true },
{ volume::P2V4, "copyright.xhtml"sv, "Text/copyright.xhtml"sv, "application/xhtml+xml"sv, std::make_optional<std::string_view>("Copyright"sv), true },
        });

    constexpr std::array _part_2_list = std::to_array<std::span<const volume_definition>>({
            std::span(vol_1), std::span(vol_2), std::span(vol_3), std::span(vol_4)
    });

    std::set<std::string> string_set;

std::vector<volume_definition> _make_part_2()
    {
        std::vector<volume_definition> x;
        x.reserve(vol_1.size() + vol_2.size() + vol_3.size());
        auto view { std::ranges::views::filter(std::ranges::join_view(_part_2_list), utils::filter_chapter_stylesheet{}) };
        std::ranges::transform(view, std::back_inserter(x), utils::transform_unique_ids{string_set, "part2"});
        std::ranges::stable_sort(x);
        std::ranges::for_each(x, utils::foreach_label{}); // Must be done in order after sort
        return x;
    }

    const std::vector<volume_definition> _part_2 = _make_part_2();
} // namespace

namespace part_2
{
    using namespace std::string_view_literals;

    std::span<const volume_definition>
    get_vol_1()
    {
        return std::span<const volume_definition>(vol_1);
    }

    std::span<const volume_definition>
    get_vol_2()
    {
        return std::span<const volume_definition>(vol_2);
    }

    std::span<const volume_definition>
    get_vol_3()
    {
        return std::span<const volume_definition>(vol_3);
    }

    std::span<const volume_definition>
    get_vol_4()
    {
        return std::span<const volume_definition>(vol_4);
    }

    std::span<const volume_definition>
    get_part_2()
    {
        return std::span<const volume_definition>(_part_2);
    }
}
