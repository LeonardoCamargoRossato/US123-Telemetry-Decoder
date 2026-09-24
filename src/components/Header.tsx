type P={page:string,setPage:(p:'monitor'|'algorithms')=>void};
export default function Header({page,setPage}:P){
  return <header className="site-header">
    <div className="header-inner">
      <div className="brand">
        <img className="ita-logo" src={`${import.meta.env.BASE_URL}assets/ITA_logo.png`} alt="Instituto Tecnológico de Aeronáutica" />
        <div><b>US123 — Telemetry Decoder</b><small>SPRB-TR/BD • Sistemas de Tempo Real</small></div>
      </div>
      <nav aria-label="Navegação principal">
        <button className={page==='monitor'?'active':''} onClick={()=>setPage('monitor')}>Monitor</button>
        <button className={page==='algorithms'?'active':''} onClick={()=>setPage('algorithms')}>Algoritmos</button>
      </nav>
    </div><div className="ita-stripe"><i/><i/><i/></div>
  </header>
}
