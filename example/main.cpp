/*
    Borealis, a Nintendo Switch UI Library
    Copyright (C) 2019-2020  natinusala
    Copyright (C) 2019  p-sam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>

#include <borealis.hpp>
#include <string>

#include "sample_installer_page.hpp"
#include "sample_loading_page.hpp"

std::vector<std::string> NOTIFICATIONS = {
    "You have cool hair",
    "I like your shoes",
    "borealis is powered by nanovg",
    "The Triforce is an inside job",
    "Pozznx will trigger in one day and twelve hours",
    "Aurora Borealis? At this time of day, at this time of year, in this part of the gaming market, located entirely within your Switch?!",
    "May I see it?",
    "Hmm, Steamed Hams!"
};

int main(int argc, char* argv[])
{
    // Init the app
    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);
    



    if (!brls::Application::init("Borealis example"))
    {
        brls::Logger::error("Unable to init Borealis application");
        return EXIT_FAILURE;
    }



    // Title and icon
    brls::TabFrame* rootFrame = new brls::TabFrame();
    rootFrame->setTitle("Nihonjin4Switch");
    rootFrame->setIcon(BOREALIS_ASSET("icon/borealis.jpg"));

    


    //Hiriganna
    brls::List* Hirigana = new brls::List();

    brls::ListItem* Ahira = new brls::ListItem("A");
    Ahira->getClickEvent()->subscribe([](brls::View* view) {
        brls::TabFrame* popupTabFrame = new brls::TabFrame();
        popupTabFrame->setHeight(255);
        popupTabFrame->setWidth(255);
        popupTabFrame->addTab("Cat", new brls::Image(std::string("Cat.jpg")));
        popupTabFrame->addTab("Dog", new brls::Rectangle(nvgRGB(124, 220, 95))); 
        brls::PopupFrame::open("Popup title", BOREALIS_ASSET("wCat.jpg"), popupTabFrame, "Subtitle left", "Subtitle right");
    });
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //to show the buttons 
    Hirigana->addView(Ahira);
    Hirigana->setParent(Ahira);
    
    
    
    
    
    
    
    
    
        
    
    
    
    //just a label
    brls::Label* testLabel = new brls::Label(brls::LabelStyle::REGULAR, " Visit My Github for more cool Projects", true);
    Hirigana->addView(testLabel);

    brls::List* Quitz = new brls::List();
    brls::ListItem* crashItem = new brls::ListItem("Do You Want to Quit?");
    crashItem->getClickEvent()->subscribe([](brls::View* view) { brls::Application::crash("The software Has Been closed "); });
    Quitz->addView(crashItem);






    //KAKATANA
    brls::List* Katakanna = new brls::List();

 
    brls::ListItem* Akata = new brls::ListItem("A");
    Akata->getClickEvent()->subscribe([](brls::View* view) {
        brls::TabFrame* popupTabFrame = new brls::TabFrame();
        popupTabFrame->addTab("Cat", new brls::Image("icon/cat.jpg"));;
        brls::PopupFrame::open("Popup title", BOREALIS_ASSET("icon/Cat.jpg"), popupTabFrame, "Subtitle left", "Subtitle right");
    });

    //to show the buttons 
    Katakanna->addView(Akata);





    rootFrame->addTab("Hirigana", Hirigana);
    rootFrame->addTab("Katakanna", Katakanna);
    rootFrame->addSeparator();
    rootFrame->addTab("Quit", crashItem);
    



    // Add the root view to the stack
    brls::Application::pushView(rootFrame);

    // Run the app
    while (brls::Application::mainLoop())
        ;

    // Exit
    return EXIT_SUCCESS;
}
