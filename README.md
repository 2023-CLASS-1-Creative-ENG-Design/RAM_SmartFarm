# RAM_SmartFarm
## 기초창의공학설계 9팀 RAM SmartFarm
RAM = Random Access Memory, 무작위로 모인 사람들이 다 같이 힘을 합해 하나의 프로젝트를 완성한다는 의미<br/>
프로젝트 : Arduino Smart Farm
<br/><br/><br/>

## 🌱 스마트팜이란?
스마트팜은 현대 기술을 활용하여 농업을 최적화하고 생산성을 높이기 위한 혁신적인 농업 시스템을 말합니다.

전통적인 농업 방식과는 달리, 스마트팜은 센서, 자동화, 인터넷 연결 등의 기술을 통합하여 농작물 생산 및 관리를 효과적으로 수행합니다.

이 스마트팜 시스템으로 농업 시스템을 발전시키는 것을 넘어 다양한 측면에서 다음과 같은 효과를 볼 수 있습니다.

환경적 측면 : 변화하는 날씨 변화에 유연하게 대처하며 여러 변수를 차단<br/>
사회적 측면 : 시골 노동력 저하 문제를 해소하고, 토지를 효율적으로 활용<br/>
경제적 측면 : 판매하는 농산물 품질을 개선, 사용자는 보다 합리적인 가격에서 구매 가능<br/>

따라서, 저희 팀은 이 스마트팜 시스템을 아두이노로 구현하는 것을 목표로 하였습니다.
<br/><br/><br/>

## 💻 어떻게 만들었나요?

![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)

최대한 저희의 힘으로 만들어보고자 최대한 제공받은 아두이노 세트와 가지고 있던 부품만으로 제작을 하였고,<br/>
토양 습도 센서, 워터 펌프와 같이 반드시 필요한 부품만 주문하였습니다.<br/>

우선 **TinkerCad**를 이용해 각각의 센서들에 대한 회로도를 작성하고 그에 맞는 개별 코드를 작성하었습니다.<br/>
(각 회로도는 **회로 사진 모음** 폴더 참조)<br/>
각 센서들의 설계가 완료되면 그것들을 한데 모아 통합 회로도를 만들고 각 코드가 충돌하지 않게 수정하였습니다.<br/>
(Arduino Code -> **SmartFarm.ino** 참조)

![image10](https://github.com/2023-CLASS-1-Creative-ENG-Design/RAM_SmartFarm/assets/29522161/491edb7a-e852-4560-8131-f910d5cc7d64)
<br/><br/>

위 통합 회로도를 기반으로 하여 팀원들이 다 같이 모여 아래 사진과 같이 아두이노 하드웨어 제작을 하였고,<br/>
마지막 주에는 각 센서들을 테스트 및 보완하고 시연을 위한 틀을 완성하였습니다.

<img
  src="https://github.com/2023-CLASS-1-Creative-ENG-Design/RAM_SmartFarm/assets/29522161/6454e26a-45d0-4c8d-9e4b-e7d4bf390f61"
  width="756"
  height="480"
/>
<br/><br/><br/>

## 📅 Schedule
1주차 : 프로젝트 전체 설계 및 개발 계획서 작성 (개발 계획서 참조)<br/>
2주차 : 조도 센서, 온습도 센서 회로도 및 코드 작성 (1차 연구발표 참조)<br/>
3주차 : 토양 습도 센서, 워터 펌프, LCD, LCD(I2C) 회로도 및 코드 작성 (2차 연구발표 참조)<br/>
4주차 : 각 센서들을 하나로 모아 전체 회로도 작성 및 코드 통합 / 하드웨어 제작 (3차 연구발표 참조)<br/>
5주차 : 센서 테스트 후 임계값 설정, 하드웨어 완성, 제품 형태 완성 (최종발표)<br/>
<br/>
(구체적인 내용은 파일 참조)
<br/><br/><br/>

## 🙋 Contact

<img
  src="https://github.com/2023-CLASS-1-Creative-ENG-Design/RAM_SmartFarm/assets/29522161/19223b5c-8ccc-48c2-b71c-707209c6bd86"
  width="729"
  height="547"
/>


김도현(팀장) / 2017112719 / goat4628 (github)<br/>
정언우 / 2023009655 / Eonuo3 (github)<br/>
문예강 / 2023007846 / MNYEGANG (github)<br/>
김승우 / 2023003106 / winu303 (github)<br/>
이동건 / 2022116761 / clhl1 (github)<br/>
