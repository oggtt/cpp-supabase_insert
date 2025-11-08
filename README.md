📚Overview
This sample project demonstrates how to perform data insertion into Supabase using C++ via HTTP requests.

Required Libraries
curl (for HTTP communication)

nlohmann-json (for JSON handling)

Setup Instructions
Install vcpkg

Use vcpkg to install the required libraries

Build the project using CMake

API Configuration
Set your Supabase URL and API KEY in main.cpp

How to Run
bash
mkdir build && cd build
cmake ..
make

🔧 Used Libraries and Licenses
🌀 libcurl
This SDK uses libcurl for HTTP communication.

License: MIT/X style

Copyright: © 1996–2025 Daniel Stenberg and many contributors

License Text: curl license

Permission to use, copy, modify, and distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND...

※ Full license text is available at the official curl site

🧩 JSON Library (Optional)
Currently, this SDK does not use a JSON library. If needed in future versions, we plan to use nlohmann/json, which is also MIT licensed.

License: MIT License

Copyright: © 2013–2025 Niels Lohmann

License Text: nlohmann/json license

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files...

🛡️ Redistribution Notes
This SDK is currently distributed as source code only.

When redistributing binaries or modified versions, please ensure that:

The original license texts are included.

Credit is given to the original authors.

No misleading use of the authors' names in advertising or promotion.

License Text: [curl license](https://curl.se/docs/copyright.html)
License Text: [nlohmann/json license](https://github.com/nlohmann/json#license)

Note: This SDK currently does not redistribute libcurl or any JSON library binaries.  
However, source code includes references to these libraries, and users are responsible for complying with their respective licenses when building or distributing derived works.
