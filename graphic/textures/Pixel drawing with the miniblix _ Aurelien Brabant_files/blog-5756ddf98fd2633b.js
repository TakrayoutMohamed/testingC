(self.webpackChunk_N_E=self.webpackChunk_N_E||[]).push([[195],{5423:function(e,t,n){(window.__NEXT_P=window.__NEXT_P||[]).push(["/blog",function(){return n(3459)}])},7624:function(e,t,n){"use strict";n.d(t,{o:function(){return r}});var r={"aurelien-brabant":{name:"Aur\xe9lien Brabant",description:"Lorem ipsum dolor sin amet blabla....",photoUrl:"/authors/aurelien.webp"}}},3459:function(e,t,n){"use strict";n.r(t),n.d(t,{__N_SSG:function(){return E},default:function(){return _}});var r=n(5893),a=n(3541),l=n(7294),s=n(5675),o=n(4320),i=n(3447),c=n(1664),u=n(7624),d=n(5985);function m(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function f(e,t){if(null==e)return{};var n,r,a=function(e,t){if(null==e)return{};var n,r,a={},l=Object.keys(e);for(r=0;r<l.length;r++)n=l[r],t.indexOf(n)>=0||(a[n]=e[n]);return a}(e,t);if(Object.getOwnPropertySymbols){var l=Object.getOwnPropertySymbols(e);for(r=0;r<l.length;r++)n=l[r],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(a[n]=e[n])}return a}var h={blue:"bg-blue-500/20 text-blue-500",gray:"bg-gray-500/20 text-gray-500",pink:"bg-pink-500/20 text-pink-500",default:"bg-neutral-500/20 text-neutral-500",yellow:"bg-yellow-500/20 text-yellow-500",orange:"bg-orange-500/20 text-orange-500",purple:"bg-purple-500/20 text-purple-500"},x=function(e){var t=e.name,n=e.color,r=e.as,a=e.className,s=f(e,["name","color","as","className"]);return(0,l.createElement)(r||"span",function(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{},r=Object.keys(n);"function"===typeof Object.getOwnPropertySymbols&&(r=r.concat(Object.getOwnPropertySymbols(n).filter((function(e){return Object.getOwnPropertyDescriptor(n,e).enumerable})))),r.forEach((function(t){m(e,t,n[t])}))}return e}({className:(0,d.A)(a,"rounded-md px-2 py-1 text-sm font-semibold",h[n])},s),t)};var p=l.forwardRef((function(e,t){return l.createElement("svg",Object.assign({xmlns:"http://www.w3.org/2000/svg",fill:"none",viewBox:"0 0 24 24",strokeWidth:2,stroke:"currentColor","aria-hidden":"true",ref:t},e),l.createElement("path",{strokeLinecap:"round",strokeLinejoin:"round",d:"M21 21l-6-6m2-5a7 7 0 11-14 0 7 7 0 0114 0z"}))})),g=n(4634),b=n(7082),v=n(4507),w=n(9008),j=n(1163);function y(e,t){(null==t||t>e.length)&&(t=e.length);for(var n=0,r=new Array(t);n<t;n++)r[n]=e[n];return r}function N(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function k(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{},r=Object.keys(n);"function"===typeof Object.getOwnPropertySymbols&&(r=r.concat(Object.getOwnPropertySymbols(n).filter((function(e){return Object.getOwnPropertyDescriptor(n,e).enumerable})))),r.forEach((function(t){N(e,t,n[t])}))}return e}function O(e){return function(e){if(Array.isArray(e))return y(e)}(e)||function(e){if("undefined"!==typeof Symbol&&null!=e[Symbol.iterator]||null!=e["@@iterator"])return Array.from(e)}(e)||function(e,t){if(!e)return;if("string"===typeof e)return y(e,t);var n=Object.prototype.toString.call(e).slice(8,-1);"Object"===n&&e.constructor&&(n=e.constructor.name);if("Map"===n||"Set"===n)return Array.from(n);if("Arguments"===n||/^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(n))return y(e,t)}(e)||function(){throw new TypeError("Invalid attempt to spread non-iterable instance.\\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method.")}()}var S="http://localhost:3000",E=!0,_=function(e){var t=e.blogpostOverviews,n=(0,j.useRouter)(),m=n.query.tags,f=n.query.search,h=u.o["aurelien-brabant"],y=(0,l.useMemo)((function(){return function(e,t){var n=new Set,r=[],a=!0,l=!1,s=void 0;try{for(var o,i=e[Symbol.iterator]();!(a=(o=i.next()).done);a=!0){var c=o.value,u=t(c);n.has(u)||(n.add(u),r.push(c))}}catch(d){l=!0,s=d}finally{try{a||null==i.return||i.return()}finally{if(l)throw s}}return r}(t.reduce((function(e,t){var n=t.tags;return O(e).concat(O(n))}),[]),(function(e){return e.name}))}),[]),N=(0,l.useState)(t),E=N[0],_=N[1],A=(0,l.useState)([]),L=A[0],C=A[1],P=(0,l.useState)(""),T=P[0],D=P[1];(0,l.useEffect)((function(){m&&C((null===m||void 0===m?void 0:m.split(","))||[])}),[m]),(0,l.useEffect)((function(){void 0!==f&&D(f)}),[f]);(0,l.useEffect)((function(){var e=L.join(",");!function(e){var t=new URLSearchParams(window.location.search);for(var n in e){var r=e[n];null===r?t.delete(n):t.set(n,String(r))}if("undefined"!==typeof history.pushState){var a="".concat(window.location.protocol,"//").concat(window.location.host).concat(window.location.pathname).concat(t.toString()?"?":"").concat(t.toString());window.history.pushState({path:a},"",a)}}({tags:""!==e?e:null})}),[L]);var B=(0,l.useMemo)((function(){return t.filter((function(e){return 0===L.length||e.tags.find((function(e){return!!L.includes(e.name)}))}))}),[L]),M=(0,l.useMemo)((function(){return B.filter((function(e){return""===T.trim()||(0,v.ND)(T.trim(),function(e){return O(e.title.split(" ")).concat(O(e.description.split(" ")),O(e.tags.map((function(e){return e.name}))))}(e))}))}),[T,B]);return(0,r.jsxs)(r.Fragment,{children:[(0,r.jsxs)(w.default,{children:[(0,r.jsx)("title",{children:"Blog | Aurelien Brabant"}),(0,r.jsx)("meta",{name:"description",content:"Read my thoughts about programming, blockchain and tech in general."}),(0,r.jsx)("link",{rel:"canonical",href:"".concat(S,"/blog")}),(0,r.jsx)("meta",{property:"og:title",content:"Blog | Aurelien Brabant"}),(0,r.jsx)("meta",{property:"og:description",content:"Read my thoughts about programming, blockchain and tech in general."}),(0,r.jsx)("meta",{property:"og:url",content:S}),(0,r.jsx)("meta",{property:"og:type",content:"website"})]}),(0,r.jsxs)("div",{className:"mx-auto max-w-7xl",children:[(0,r.jsx)(o.Z,{}),(0,r.jsx)(a.pT,{children:(0,r.jsxs)("div",{className:"relative bg-dark px-4 pt-16 pb-20 sm:px-6 lg:px-8 lg:pt-24 lg:pb-28",children:[(0,r.jsx)("div",{className:"absolute inset-0",children:(0,r.jsx)("div",{className:"h-1/3 bg-dark sm:h-2/3"})}),(0,r.jsxs)("div",{className:"relative mx-auto max-w-7xl",children:[(0,r.jsxs)("div",{className:"relative rounded-lg py-6 text-center md:py-10 lg:py-16",children:[(0,r.jsx)(s.default,{src:"/landing-bg.jpg",layout:"fill",objectFit:"cover",className:"z-10 opacity-20",alt:"blog heading section abstract banner picture"}),(0,r.jsxs)("div",{className:"relative z-20",children:[(0,r.jsxs)("h2",{className:"text-3xl font-extrabold tracking-tight text-white sm:text-5xl",children:["From the"," ",(0,r.jsx)("span",{className:"text-orange-400",children:"Blog"})]}),(0,r.jsx)("p",{className:"mx-auto mt-3 max-w-2xl text-xl text-white/90 sm:mt-4",children:"My thoughts about programming, blockchain and tech in general"})]})]}),(0,r.jsxs)("div",{className:"mt-12 flex flex-col-reverse md:flex-row md:items-stretch",children:[0===M.length?(0,r.jsxs)("div",{className:"mt-12 flex w-full flex-col items-center justify-center gap-y-8 text-center text-white/90 md:w-[75%] lg:mt-0",children:[(0,r.jsx)(p,{className:"h-10 w-10"}),(0,r.jsx)("h2",{className:"text-xl",children:"Oh no! No post is matching your criterias."})]}):(0,r.jsx)("div",{className:"mx-auto mt-8 grid max-w-lg grid-cols-1 gap-5 md:mt-0 md:w-[75%] lg:max-w-none lg:grid-cols-2",children:M.sort((function(e,t){return new Date(e.lastEditedTime).getTime()-new Date(t.lastEditedTime).getTime()})).map((function(e,t){return(0,r.jsx)(a.pT,{duration:500,className:"h-full",children:(0,r.jsx)(c.default,{href:"/blog/".concat(e.slug),children:(0,r.jsxs)("a",{className:(0,d.A)("flex h-full flex-col overflow-hidden rounded-lg p-2 shadow-lg transition-all hover:ring-2 hover:ring-orange-400/50 active:ring-orange-400 lg:mt-0",0==t&&"lg:col-span-2"),children:[(0,r.jsxs)("div",{className:"relative h-48 flex-shrink-0",children:[(0,r.jsx)("div",{className:"absolute inset-0 z-10 flex h-48 w-full items-center justify-center bg-04dp",children:(0,r.jsx)(g.Z,{className:"h-16 w-16 animate-pulse text-white/30"})}),(0,r.jsx)("img",{className:"absolute z-20 h-48 w-full object-cover",src:e.coverUrl||"",alt:""})]}),(0,r.jsxs)("div",{className:"flex flex-1 flex-col justify-between bg-01dp p-6",children:[(0,r.jsxs)("div",{className:"flex-1",children:[(0,r.jsx)("div",{className:"flex flex-wrap gap-2",children:e.tags.map((function(e){return(0,r.jsx)(x,k({},e),e.name)}))}),(0,r.jsx)("p",{className:"mt-4 text-xl font-semibold text-white/90",children:e.title}),(0,r.jsx)("p",{className:"mt-3 text-base text-white/80",children:e.description})]}),(0,r.jsxs)("div",{className:"mt-6 flex items-center",children:[(0,r.jsxs)("div",{className:"flex-shrink-0",children:[(0,r.jsx)("span",{className:"sr-only",children:"Some name"}),(0,r.jsx)("div",{className:"relative h-10 w-10 overflow-hidden rounded-full",children:(0,r.jsx)(s.default,{src:h.photoUrl,alt:"picture of ".concat(h.name),layout:"fill"})})]}),(0,r.jsxs)("div",{className:"ml-3",children:[(0,r.jsx)("p",{className:"text-sm font-medium text-white/80",children:(0,r.jsx)("span",{className:"hover:underline",children:u.o["aurelien-brabant"].name})}),(0,r.jsxs)("div",{className:"flex space-x-1 text-sm text-white/80",children:[(0,r.jsx)("time",{dateTime:new Date(e.createdTime).toDateString(),children:new Date(e.createdTime).toDateString()}),(0,r.jsx)("span",{"aria-hidden":"true",children:"\xb7"}),(0,r.jsx)("span",{children:"5 min. read"})]})]})]})]})]})})},e.slug)}))}),(0,r.jsxs)("aside",{className:"top-8 max-w-full self-start md:sticky md:ml-6 md:border-l-2 md:border-04dp md:py-2 md:pl-6 lg:w-[25%]",children:[(0,r.jsxs)("div",{children:[(0,r.jsx)("label",{htmlFor:"search-blogpost",className:"sr-only block text-sm font-medium text-gray-700",children:"Search blogpost"}),(0,r.jsxs)("div",{className:"relative mt-1 rounded-md shadow-sm",children:[(0,r.jsx)("input",{type:"text",name:"search-blogpost",id:"search-blogpost",className:"block w-full rounded-md border-04dp bg-02dp pr-10 text-white/90 focus:border-orange-500/50 focus:ring-orange-500/50 sm:text-sm",placeholder:"ReactJS, Solidity",autoComplete:"off",value:T,onChange:function(e){var t=e.target.value;D(t),_(E.filter((function(e){return e.title.toLowerCase().includes(t.toLowerCase())})))}}),(0,r.jsx)("div",{className:"pointer-events-none absolute inset-y-0 right-0 flex items-center pr-3",children:(0,r.jsx)(p,{className:"h-5 w-5 text-gray-400","aria-hidden":"true"})})]})]}),(0,r.jsxs)("div",{className:"mt-8",children:[(0,r.jsxs)("h2",{className:"text-2xl font-semibold text-white",children:[(0,r.jsx)(b.Z,{className:"mr-1 inline-block h-5 w-5"})," ","Tags"]}),(0,r.jsx)("ul",{className:"mt-8 flex flex-wrap items-start gap-4 text-white/90 md:flex-col",children:y.map((function(e){return(0,r.jsx)(x,k({className:(0,d.A)(!L.includes(e.name)&&"opacity-60"),as:"button"},e,{onClick:function(){return t=e.name,void(L.includes(t)?C(L.filter((function(e){return e!==t}))):C(O(L).concat([t])));var t}}),e.name)}))})]})]})]})]})]})}),(0,r.jsx)(i.Z,{})]})]})}},4507:function(e,t,n){"use strict";n.d(t,{Au:function(){return r},ND:function(){return l}});var r=function(e,t){return e.split("\n").slice(0,t).join("\n")},a=function(e){return e.normalize("NFD").replace(/[\u0300-\u036f]/g,"")},l=function(e,t){var n=t.map((function(e){return a(e).toLowerCase()}));return a(e).toLowerCase().split(" ").every((function(e){return n.find((function(t){return t.includes(e)}))}))}},7082:function(e,t,n){"use strict";var r=n(7294);const a=r.forwardRef((function(e,t){return r.createElement("svg",Object.assign({xmlns:"http://www.w3.org/2000/svg",fill:"none",viewBox:"0 0 24 24",strokeWidth:2,stroke:"currentColor","aria-hidden":"true",ref:t},e),r.createElement("path",{strokeLinecap:"round",strokeLinejoin:"round",d:"M13.828 10.172a4 4 0 00-5.656 0l-4 4a4 4 0 105.656 5.656l1.102-1.101m-.758-4.899a4 4 0 005.656 0l4-4a4 4 0 00-5.656-5.656l-1.1 1.1"}))}));t.Z=a},4634:function(e,t,n){"use strict";var r=n(7294);const a=r.forwardRef((function(e,t){return r.createElement("svg",Object.assign({xmlns:"http://www.w3.org/2000/svg",fill:"none",viewBox:"0 0 24 24",strokeWidth:2,stroke:"currentColor","aria-hidden":"true",ref:t},e),r.createElement("path",{strokeLinecap:"round",strokeLinejoin:"round",d:"M4 16l4.586-4.586a2 2 0 012.828 0L16 16m-2-2l1.586-1.586a2 2 0 012.828 0L20 14m-6-6h.01M6 20h12a2 2 0 002-2V6a2 2 0 00-2-2H6a2 2 0 00-2 2v12a2 2 0 002 2z"}))}));t.Z=a}},function(e){e.O(0,[589,750,774,888,179],(function(){return t=5423,e(e.s=t);var t}));var t=e.O();_N_E=t}]);