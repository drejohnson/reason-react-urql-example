open ReasonUrql;

open BsReactHead.ReactHead;

open UrqlClient;

[@bs.module "./serviceWorker"]
external serviceWorker: unit => unit = "default";

ReactDOMRe.renderToElementWithId(
  <Provider client> <HeadProvider> <App /> </HeadProvider> </Provider>,
  "root",
);

serviceWorker();

type hot;

[@bs.deriving abstract]
type parcelModule = {hot: option(hot)};

[@bs.val] external parcelModule: parcelModule = "module";
[@bs.send] external accept: (hot, unit) => unit = "accept";

switch (parcelModule->hotGet) {
| Some(h) => h->accept()
| _ => Js.log("We are not hot")
};